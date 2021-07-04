#include <iostream>

/*
    Templates are like generics, just much more powerful
    
    Why would we need template?
        -> We can create a generic function or something like that, so that we do not need a bunch of overloads for same function


    How does this work?
        -> When we use the keyword template before a method call
        -> We are telling the compiler that this is a template that will be evaluated at the compile time
        -> This also means, until the code is compiled and actually run, based on the input the value the function with right paramters will be created

        -> 'typename' is a template parameter
            -> It means, when we call the function in main or somewhere else, with whatever argument we call
                -> the method is converted to have that data type as parameter, and the method is called

            -> We can make it a little faster by calling the function with data type in angular brackeets
                -> print<int> (5);
                -> print<std::string> ("Hello world\n");
                -> Something like this ...

        -> Since it is identified at run-time, we can also use it to allocate array memory on stack
            -> The size will be a template type
*/

class Entity
{
private:
    int id;
    std::string name;

public:
    Entity(int id, std::string name)
    {
        this->id = id;
        this->name = name;
    }

    friend void operator<<(std::ostream &o, Entity &e);
};

template <int N>
class Array
{
private:
    int arr[N];

public:
    int getSize() const
    {
        return N;
    }
};

void operator<<(std::ostream &o, Entity &e)
{
    o << e.id << "\n";
}

template <typename T>
void print_something(T val)
{
    std::cout << val;
}

int main()
{
    print_something<int>(5);
    print_something<std::string>("Hello");

    Entity e1(1, "one");
    std::cout << e1;

    Array<10> a;
    std::cout << a.getSize();
}