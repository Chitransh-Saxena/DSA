#include <iostream>

/*
    What is pointer?
    -> A pointer is a type of variable that stores the address of some other variable
    -> So, a pointer of type int (int* a) stores the address of another int type variable
    -> Since the pointer stores an address in memory, it can be dereferenced to see what is stored in that memory address.
*/


void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void swapPtr(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main ()
{
    int a = 10;
    int* a_ptr = &a;    // Storing the address of a (&a) in the variable a_ptr of type int*

    std::cout << "Address of a = " << a_ptr << "\n";
    std::cout << "Value in address a = " << *a_ptr << "\n";

    // We can increament the pointer value - a_ptr++. This will take us to the next memory address
    // If current memory address in 2000, and if ptr is of 'int' type, the next address will curr + 4 bytes (because int in 64_bit is 4 bytes)
    // If I had char in place of int, next address would be seen 

    std::cout << "Next memory address is " << ++a_ptr << "\n";

    int arr[] = {10, 20, 30};

    // When we dereference the array name, we are actually referring to the first block of memory's value
    std::cout << *arr << std::endl;

    int *ptr = arr;     // This pointer will help in printing the entire array
    for(int i = 0; i < 3; i++)
    {
        std::cout << *ptr++ << "\n";
        // If I am able to get first element with *arr, why am I not increamenting *arr++, and fetching values? That just gives error, thats why
        // std::cout << *arr++ << "\n";     error: lvalue required as increment operand. 

        /* lvalue is something that can actually have a value
            i = 10; i is lvalue here
            i + 1 = 25;     Maths says i = 24 here, but i+1 is not an lvalue anymore, so it cannot store a value

            But in case of arrays, the name of array is non-modifiable l-vlaue.
                -> It cannot be assigned
                -> It's address can be taken
        */

       std::cout << *(arr+i) << "\n";
    }

    int **q = &a_ptr;
    std::cout << "Dereferencing double pointer once *q = " << *q << "\n";
    std::cout << "Dereferencing double pointer twice **q = " << **q << "\n";        // Since we increamented a_ptr, at line 22, we get garbage value here


    int x = 5, y = 10;
    swap(x, y);

    std::cout << "x = " << x << " and y = " << y << std::endl; // Even after swap is called, the value does not change, because the swap happens in the scope of function and does not change the original variable


    // If we pass by reference, we are basically passing the address of those variables, and operating on the memory directly
    swapPtr(&x, &y);
    std::cout << "x = " << x << " and y = " << y << std::endl;
}