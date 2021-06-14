/*
    We know that a thread can either be joined or detached only once
    But if a thread object is destroyed before it is joined or detached, then the program will terminate

    So, we have to decide wether to join the thread or detach the thread before t1 goes out of scope

*/

#include <iostream>
#include <thread>

void methSomething()
{
    std::cout << "Print something\n";
}


class Functor
{
    public:
        void operator()(std::string msg)
        {
            std::cout << "t1 says : " << msg << std::endl;
        }
};

int main()
{
    // std::thread t1 (methSomething);             // t1 starts running


    // Threads can be called upon anything callable (functions, functors, lambda)
    Functor f1;
    std::thread t1(f1, "Life is more than success\n");


    /* Once the child thread starts running, and before it is joined, we should be doing some work, (in practical scenarios)
    for(int i = 0; i<100; i++)
        std::cout << "Print: " << i << std::endl;

    */


    // Above scenario is fine, but imagine, if for some reason there is a complex code, which throws an exception
    // So, then again the thread object t1 will be destroyed before it is joined because the main thread itself is not there anymore
    // In that case, we can use a try catch block to join back the thread t1;

    try
    {
        for(int i = 0; i<100; i++)
        {
            std::cout << "Printing: " << i << std::endl;
        }

    }
    catch(...)
    {
        t1.join();
        throw;
    }

    // So above approach works just fine, but there is another work around.
    // We can wrap the main thread functionality in a class method and call the join in that class's destructor

    t1.join();
    return 0;
    
}