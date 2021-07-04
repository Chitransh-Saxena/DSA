#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

/*
    What is lambda?
        -> It is a kind of function ( it is actually a function ), which is defined inside another function or a class and is used there locally (sometimes globally too)
        -> It is more like a function which has such small functionality that we wanna treat it like a variable.
        -> lambdas are by default inline
            -> inline is something whose logic is copied and pasted at the point where it is called so that the compiler's overhead to actually call the method is reduced
            -> Consider this, iterating from line 1 to line 2 is basically 1 CPU instruction
                -> Calling a function and getting a return value is somewhat like 2 or 3


    What is it used for?
        -> Whenever we have a function pointer (yet to write about it, but it is basically a pointer which points to the block of memory which is holding the logic of some method), we can have a lambda
        -> Lambda is just a way to define a function, without having to physically write a function
        -> We can use them like custom comparators to STL functions like sort, find etc.
            -> Imagine, we are passing a function as a parameter to another function, this is literally the function of a function pointer or a lambda
            -> This is the powerful thing that a lambda offers

    Lambda - 
        auto lambda = [](){};
            -> [] = This is called capture. We pass in the way things are gonna be taken, like pass by reference or pass by value
                -> This is different from a function (lambda parameter), this is capture
                -> Capture basically takes in the value that is outside the lambda
                -> Consider this, lambda is still a function, any variable out of a function is not accessible unless it is global
                -> So, in case of lambda, to make that variable accessible, we use 'capture'
                    -> [&] = This means all the variables used, will be passed by reference
                        -> When we pass a variable by reference, we can change the value of that variable. This is not allowed when passed by copy
                        -> To achieve this change, we use 'mutable'
                    -> [=] = This means all the variables used, will be passed by copy and current object by reference (if it exists)
                    -> [this] = This captures the current object by reference
                    -> [a, &b] = Captures a by copy and b by reference
                    -> [] = Captures nothing
            
            -> () = This is same as regular function bracket, pass in the parameters, stay happy
*/

// NOTE: This is how a function pointer or a lambda is passed in to a function
// return type (*name_of_lamda)(data type of the parameter that is passed to it). Example: void(*lamb)(int)
for_each(const std::vector<int> &v, void(*func)(int))
{
    for(int val: v)
    {
        func(val);
    }
}


// This is how we pass a lambda to a function, we use std::function to convert our declaration into a function
// This is confusing, so read about std::function or check how the syntax here is used
for_each2(const std::vector<int> &v, const std::function<void(int)>& lamb )
{
    for(int val: v)
    {
        lamb(val);
    }
}

int main()
{

    std::vector<int> v = {1, 5, 4, 3, 2, 1};
    auto lamb = [](int v)
                {
                    std::cout << v << std::endl;
                };
    
    for_each(v, lamb);

    int x = 10;

    // Now above code works fine, but what if we want to pass in some other value that is not a paramter, because parameter is used at each iteration in some way ???
    // This is where capture comes in


    // Passing x by reference in the capture
    auto lamb2 = [&x](int v)
                {   
                    std::cout << x << std::endl;
                };
    

    // for_each(v, lamb2); This will throw error because of the second paramter of for_each, we have defined it for a raw function pointer. Anytime we add something in capture, that declaration will fail

    for_each2(v, lamb2);        // This works


    // If we pass in something to capture by copy and we want to make changes to it, it won't be not allowed directly, we need to use 'mutable' keyword
    auto lamb3 = [x](int v) mutable
                { 
                    x = 4;  
                    std::cout << x << std::endl;
                };

    // Now let's see it's real practical use
    // I am gonna customize the std::find_if function according to my needs
    auto it = std::find_if(v.begin(), v.end(), []( int val ){ return val > 2; });
    std::cout << "Found variable of our condition = " << *it << std::endl;
}