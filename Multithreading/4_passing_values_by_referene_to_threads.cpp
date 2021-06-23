/*
    In this example, we pass a string by reference to a method. (Two threads (main and child), are sharing a string resource)
    That method prints the string, and changes the string

    Then there are two scenarios that we notice
    1. We print the string, which was changes in thread, and then join (All of this in the main thread)
    2. We join the thread, and then print the message'


    3. There is a third scenario, where instead of passing by reference, we use std::move()


    NOTE:
    1. std::ref(string) is used to create string reference, for some reason regular pass by reference does not work here.
    2. std::move(), moves the resource from main thread to child thread. Can also basically change the ownership of the resource
    3. To get the thread id, we can use thread::get_id();
*/


#include <iostream>
#include <thread>
#include <string>

using namespace std;

class Functor_
{
    public:
        void operator()(std::string& s)
        {
            std::cout << "t1 says: " << s << std::endl;
            s = "I am changing the message now\n";
        }
};

int main()
{
    std::cout << "Main thread_id = " << std::this_thread::get_id() << std::endl;
    
    std::string s = "There is a message\n";
    Functor_ f1;
    std::thread t1(f1, std::ref(s));
    // std::thread t1(f1, std::move(s));            // Does not compile

    std::cout << "t1 id = " << t1.get_id() << std::endl;

    std::thread t2 = std::move(t1);

    std::cout << "t2 id = " << t2.get_id() << std::endl;
    t2.join();
    // Now, since i have called the thread which is changing the value of s, it is supposed to change since I passed the value by reference
    std::cout << "Main thread says: " << s << std::endl;

    // t1.join();           If I join the thread afterwards, the changed message would not be printed
}