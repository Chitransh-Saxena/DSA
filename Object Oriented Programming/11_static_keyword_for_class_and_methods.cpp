/*
    Static has 2 contexts

    1. If defined inside a class, then it is gonna be shared across all the instances of the class across all translation units (.cpp, .c files)
        -> Across all the classes or structs, there is only going to be one instance of that static variable
    2. If it is defined outside a class, it is gonna be there for only that translation unit
        -> This makes sense, because how else we would share a variable to another translation unit unless they are linked via some mechanism
    3. With methods, there is a different scenario
*/

/*
    Scenario 1:
        -> When any variable is defined and used as `static int x = 5` in any .cpp file, it basically tells the Linker to not look for it's definition in any other trasmlational unit
        -> One work around for this kind of thing could be
            -> int x = 5;   // This is in file1.cpp
            -> extern int x;    // This is main.cpp

            -> Now, when main.cpp is compiled and linked, the linker will look for the definition of 'x' in an external translation unit.

            -> But, if in file1.cpp we make it as static int x = 5;
                -> Then, only fil1.cpp will have the scope of it
                -> Since we marked it as extern in main.cpp, it is looking for the definition outside that translational unit
                -> This will lead to compilation error
    
    Scenario 2:

        -> If a static variable is defined inside a class, it is gonna be present in the same state across all the instances of the object
        -> This means, if obj1 changes the value of static int x = 5. Then it is gonna be x = 5 for all the instances of the class of obj1

    Scenario 3:
        -> If we have a static method, then we can only access static variables
        -> static method does not have a class instance, thus it cannot refer to class's instance.

        -> But if we have static method outside the class, and we pass in the class object as the paramter, then we can access the class members
*/

#include <iostream>

struct Entity
{
    static int x, y;                // This is literally making it invisible to the Linker

    void print()
    {
        std::cout << x << " " << y << std::endl;
    }
};

// If we do not do this, the linker is gonna look for symbols to actually link the static variables, so this is that place where linker is gonna link
int Entity::x;
int Entity::y;

int main()
{
    Entity e;
    e.x = 2;
    e.y = 3;

    
    Entity e2;
    e2.x = 5;
    e2.y = 6;

    e.print();
    e2.print();

    /*
        Both print methods print the same numbers, why?
            -> Because for the static variables, e and e2 are both referring to the same memory blocks of x and y.
            -> Changing one would mean changing for other

    */

   // Since they are all shared acrross the Entity class, and not object, we can refer to them like this
   Entity::x = 10;
   e.print();

}
