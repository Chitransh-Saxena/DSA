#include <iostream>

int main () {

    // Basic Gyan - % operator does the job of checking if the number is even or odd.
    // But it is very slow, luckily we can do it faster by bit operations.

    // In Odd numbers - Right Most Bit is always 1
    // In Even numbers - Right Most Bit is always 0

    // So, at this point we know, we have to know the last bit of the number and we can tell if it is even or odd.

    // We resort to & operation at this point, if we do `number & 1`, it will do `and` operation with all the bits, and the result will be:
    // if last bit is 1, after & operation, last bit will be 1 and all other bits will be 0
    // If last bit is 0, after & operation, last bit will be 0 as well as all other bits.


    int x = 9;
    if(x&1)
        std::cout << "Odd\n";
    else
        std::cout << "Even\n";
}