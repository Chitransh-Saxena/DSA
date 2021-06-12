#include <iostream>

/* 
    Imagine a scenario, where we have a base class and a derived class
    Now, we create a function in base class, and then we create a similar method(same name, return type and args) in derived class too.
    So, what virtual function does, it helps us in executing the most derived implementation of that function.
    In complex terms, we also call it DYNAMIC POLYMORPHISM

    So, let's go pointer wise

    1. Why use virtual function?
        -> To achieve dynamic polymorphism
        -> It is the ability to call derived class method implementation using base class object
    
    2. How to use virtual function? - Refer line 12 in 6_Polynorphism.cpp

    NOTES - 

    1. A virtual function cannot be static and cannot be friend function of another class. Why?
    2. A class can have virtual destructor but not virtual constructor
    3. We have 2 types of virtual functions - 
        3.1 Virtual Functions
        3.2 Pure Virtual Functions - Which force the implementation of Interface (refer 4_Abstraction.cpp)


    ****** What is the use of virtual function apart from having the ability to call derived method from base class pointer object?

    ****** What is a vtable, how is it internally used in virtual functions? How does it come in play for virtual constructor and virtual destructor
    ****** What is dynamic dispatch?
*/