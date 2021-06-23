/*

    What we gonna study here
        -> std::unique_lock
            -> std::defer_lock
        -> Thread safety for file implementation
        -> std::once_flag


    We know about std::lock_guard (and the use of mutex's own lock and unlock is not recommended).
    But what if we need some more flexibility while locking and unlocking
    
    That's where std::unique_lock comes in place
    -> It provides a more flexible way to implement a fine grained lock
    -> We even have the flexibility to construct the locker without actually locking the mutex

    -> Unfortunately, it is more heavy weight, and thus, affects the performance
    
    -> NOTE: A wrapper class of mutex cannot be copied (lock_guard, unique_lock ... anything)
        -> Fortunately, we can move the unique_lock
        -> std::unique_lock<std::mutex> locker_2 = std::move(locker);



    LAZY INITIALIZATION
    -> We do some intializations in the constructor, but what if the required functions are never called?
    -> Then those things are never used
    -> So, we initialize those things upon first use.
        -> That's called lazy initialization
*/

// Continuing the example from lesson 5
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>


class ThreadSafe
{
    private:
        std::mutex _mu, _mu_file;
        std::ofstream _f;
        std::once_flag _flag;
    
    public:


        /*
            This method is good, but the flaw with this approach is that, if we wanna do something right after creating the mutex
            that is not possible without locking that resource

            Second flaw, we do not have the privilege to lock and unlock a resource multiple times
        */
        void sharedPrint(std::string msg)
        {
            if(!_f.is_open())
            {
                _f.open("log.txt");
            }
            std::lock_guard<std::mutex> locker(_mu);
            _f << msg << std::endl;
        }

        /*
            Gonna fix the above flaws in this implementation
            std::unique_lock provides a more flexible way to implement a fine grained lock
        */
        void sharedPrint_improved(std::string msg)
        {   
            
            /*

            Read this for File Opening Thread Safety

            // Since this part is gonna be called by multiple threads, we need to make it thread safe
            // We cannot use _mu to lock this file, because that is gonna be used several times, but the file only needs to be locked once
            if(!_f.is_open())
            {   
                // Below implementation, marks the _f.open as thread safe, but it introduces another problem
                
                    -> t1 comes and checks if file is not open, then it opens the file (also locks that operation by mutex)
                    -> At the same time, t2 also comes, checks if the file is not open, now if t1 has not yet opened the file yet, t2 will open the file
                    -> Here is our problem, same file is being opened by two threads
                    -> What could be the possible solution? We protect the is_open() function by mutex too.
                
                // std::unique_lock<std::mutex> file_locker(_mu_file);
                _f.open("log.txt");
            }

            */


           // Come here after reading file open thread safety

           /*
                -> This implementation is fine, but it hinders the performance and CPU by constantly locking the mutex, checking if the file is open or not
                -> All the locking and unlocking, just to check if the file is open is bad
                -> So, instead of using mutex, we use std::once_flag
            */

           /*
           std::unique_lock<std::mutex> file_locker(_mu_file);
           if(!_f.is_open())
           {
               _f.open("log.txt");
           }
           */


            // Come here after reading flaws of mutex on file safety
            std::call_once(_flag, [&](){
                _f.open("log.txt");             // Now, the file will be only opened once by any one thread
            });

            // std::unique_lock<std::mutex> locker(_mu);                Here, the locker is constructed and the mutex is locked then and there
            std::unique_lock<std::mutex> locker(_mu, std::defer_lock);  // Mutex is not locked yet
            // So, we can do something here, which does need to be locked by the mutex
            
            locker.lock();
            _f << msg << std::endl; 
            locker.unlock();


            // ... and we can repeat this lock and unlock 'n' number of times
        }

};