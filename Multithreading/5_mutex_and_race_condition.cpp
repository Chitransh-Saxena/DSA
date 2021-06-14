/*
    A race condition is a condition where the output of the program is relative to the execution order of one or more threads
    Example: If we are one child thread writing to console (say 1 to 100) and we our main thread doing the same thing
    The logs in the console would be pretty messed up.
    Why? Because 2 threads, t1 and main, are both racing for the same resource (Stdout)

    So, how can we handle this?

    1. Mutex - This synchronizes the access of the common resource (stdout in above case)
        1.1 We can use **mu.lock() and mu.unlock()** to lock and unlock the shared resource
        1.2 This makes sure that one resource is not accessed by 2 threads at the same time
        1.3 But what if the resource crashes for some reason?
        1.4 In that case, the resource would be locked forever

        1.5 We use lock_guard in that case
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu;

void shared_print_method(std::string s, int num)
{
    // mu.lock();                                  // Lock the upcoming resource


    // If the resource (stdout in this case) crashes for some reason, the resource will be locked forever, so we use locl_guard in that case
    std::lock_guard<std::mutex> guard(mu);         // Whenever guard goes out of scope, mutex will be unlocked with or without exception
    std::cout << s << " num = " << num << std::endl;

    
    // mu.unlock();                                // Unlock the resource

}


void thread_printer()
{
    for(int i = 0; i>-100; i--)
    {
        shared_print_method("From child thread", i);
    }
}

int main()
{
    std::thread t1(thread_printer);

    for(int i = 0; i<100; i++)
    {
        shared_print_method("From main thread", i);
    }

    t1.join();
    return 0;
}