#include <iostream>


/*
    Mostly used to define limits in the code
    const int MAX_AGE = 90


    POST CODE REVIEW - 

    -> const int* a = new int;     This means we cannot change the contents of this memory location. const int* locks the memory address (* is pointer to that address).
    -> Above also means we CAN re-assign 'a' to a different memory location. In above, const is for int* a, that means contents of 'a' are read-only
    -> int const* a = new int;     This has the same meaning as above.

    -> int* const a = new int;     Now, this means that we CAN change the contents of 'a'. But we cannot reassign 'a' to a different memory location
    -> In above, note that const is for 'a'. Which means we make the memory address 'a' as read-only

    -> const int* const a = new int;     This means we cannot modify either contents of that memory address, nor can we re-assign it to a different location
*/

class Entity
{
    private:
        int num1;
        mutable int x;
    public:

        // const at the end of this method name shows that this method is not gonna be able to modify class member variables
        // Logically, only getters are marked as const, because setters do have to modify the value
        // We can do this only in class methods, not outside the class
        int getNum1() const
        {   
            x = 50;             // Since 'x' is a mutable variable, even if it is inside a 'const' function, we can make changes to this variable
            return num1;
        }

        void setNum1(int num) {
            num1 = num;
        }

        // This is a non const function which changes num1;
        int getNumAndChangeIt()
        {
            num1+=1;
            return num1;
        }
};

// This function works just fine because it will create it's own local copy of 'e' and operate on it.
void printEntity(Entity e)
{
    std::cout << "Entity e = " << e.getNum1() << std::endl;
}

// const Entity& e enforces that do not modify the contents of address e.
void printEntity2(const Entity& e)
{
    std::cout << "Entity e = " << e.getNum1() << std::endl;

    // std::cout << "Entity e = " << e.getNumAndChangeIt() << std::endl;

    // Since we passed 'e' as const reference, we cannot call any function that does not guarantee that the contents will not be modified.
    // Since getNumAndChangeIt() is not a 'const' function, it has the right to change the contents and thus, this printEntity2() method does not allow us to call that

}

int main () 
{
    const int y = 5;            // Now it is a read -only memory block, so that memory block in RAM is now reserved for only reading, no write operation will be allowed on it
    // y+=1;                    This will give error that asssignment of read only memory block
    std::cout << "y = " << y << "\n";


    const int MAX_AGE = 90;
    int *a = new int;

    *a = 2;
    // a = &MAX_AGE;           This gives an error saying cannot convert from const int* to int*
    a = (int*)&MAX_AGE;


    // ###################################################################################################
    // Now if we wanna enforce that we cannot modify the contents of that pointer. NOTE: We cannot change the contents of that memory address, we can still assign this variable to some other memory address
    
    
    const int* b = new int;         // We could also have written it as int const* b = new int. But int* const b = new int is different 
    // *b = 50;                 This gives the error saying that we are assigning in a `read-only memory location`

    b = (int*)&MAX_AGE;


    // ###################################################################################################
    // In previous case, we added const at first, and that kind of enforced that we cannot change the contents of the pointer, now we are gonna do the opposite

    int* const c = new int;
    *c = 50;
    // c = (int*)&MAX_AGE;     This gives the error saying that we are assingnign a `read only variable`. NOTE: It does not say that we are assigning in a memory location, it is saying we are assinging in a read only variable

    // ###################################################################################################

    Entity e;
    e.setNum1(5);
    printEntity(e);
    printEntity2(e);
}
