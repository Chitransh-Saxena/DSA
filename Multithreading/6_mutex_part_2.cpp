/*
    Revision of lesson 5 - 

    In the previous example, file 5
    We saw how stdout was originally an open resource, and it was accessed by multiple threads
    That was creating a problem that the logs in console were unordered

    To overcome that, we introduced, mutex, that was locking and unlocking the shared resource
    -> std::mutex mu
        -> mu.lock()
        -> std::cout << "Jabba\n";
        -> mu.unlock();
    -> But above implementation had one problem
        -> If std::cout (the shared resource) crashes, it will stay locked forever and would not be used by any other thread
    
    -> To avoid that we used, std::lock_guard<std::mutex> guard(mu);


    About current lesson
    -> In previous lesson, we understood that std::cout is a shared resource and we are locking that
    -> But still, std::cout is a global variable, that could still be accessed by another thread that might not be accessing this mutex guard resource
    -> In that case, we could still see asynchronous behaviour of the shared resource

    -> So, how do we tackle that?
        -> For that, we are not gonna do anything new, just gonna use our own mutex locked output stream operator
        -> Basically, with the capabilities of encapsulation, we only provide those methods, which are thread and mutex safe

*/
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>



class ThreadSafe
{
    private:
        std::ofstream m_outStream;
        std::mutex m_mutex;
    
    public:

        ThreadSafe()
        {
            m_outStream.open("log.txt");
        }

        void shared_print(std::string msg, int id)
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            m_outStream << "From " << msg << " and id = " << id << std::endl;
        }

        // Never pass any function which has direct access to 'f'

};

void meth(ThreadSafe& ts, std::string msg)
{
    for(int i = 0; i>-100; i--)
    {
        ts.shared_print(msg, i);

    }
}

int main()
{
    ThreadSafe ts;
    std::thread t1(meth, std::ref(ts), "from thread t1");


    for(int i = 0; i<100; i++)
        ts.shared_print("from main thread", i);
    
    t1.join();
    return 0;
}
