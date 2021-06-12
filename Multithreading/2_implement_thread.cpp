#include <iostream>
#include <thread>

void printSomething()
{
    std::cout << "Something\n";
}

int main()
{
    thread t1(printSomething);          // thread 1 starts running
    t1.join();                          // Main thread waits for the t1 to finish and once finishes, exits from main

    return 0;
}