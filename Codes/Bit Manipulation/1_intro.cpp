#include <iostream>

using namespace std;

int main () {


    int x = 57;

    /*
        We are storing this number 57 in variable x. This number 57 is in decimal format
        But when it is stored in memory (RAM), it is stored in binary format
        57 -> 111001. This will be stored in memory
    */

    // This will print in decimal format though.
    cout << x << "\n";

    // Different data types store different amount of bytes
    /*
    * int - 32 bits or 4 bytes
    * char - 1 byte or 8 bits
    * bool - Boolean stores true or false, it stores just 1 bit
    * Float - 4 bytes
    * double - 8 bytes
    * void - valueless entity
    * wide character - wchar_t. It is generally 2-4 bytes long. It is normal char type datatype but with more size capacity
    * 
    * Now there are few more categorizations among short int, signed and unsigned int and so on...
    */

    /*
    * For a number with 8 bits, it can represent a range of 2^8 distinct numbers
    * Therefore, int - 4 bytes or 32 bits, can represent 2^32 distinct numbers.
    * The range of numbers is -2^(n-1) - 2^(n-1) -1
    * That range of numbers is calculated by following method
    */

    /* Calculating range of numbers - BINARY TO DECIMAL

    * For example, if we have 4 bits, and we wanna know the range of numbers we can create by that, we have to follow a certain method
    * Total numbers that can be created would be 2^4. So, total numbers would be 16.
    * First set of numbers would be from 0-7 (non-negative 8 integers). These can be identified as 0 as thier first set bit (MSB - Most Significant Bit)
    * Second set would be same binary numbers with but the first set bit would be 1. But that's not it
    * We take 2s compliment of those numbers (1s compliment + 1 bit addition). 1's compliment is nothing but reverting all the bits
    * 
    * This is how we get total 2^4 numbers
    * NOTE: MSB varies on the basis of endianess, we are gonna study endianess in later lessons but for now, it is the way a machine reads bits. (Left to right or Right to left)
    * So, for some computers Left Most Bit is MSB and for some, Right Most Bit
    */

    /* Converting from Decimal To Binary
    * 
    * There are following generic methods to do so, they perform differently on the basis of data type we are dealing with
    * For +ve decimal numbers, get binary number by divide by 2 prime factorization method
    * -> Now, if the binary digits are more than the limit of data type, reduce first 'n' digits to fit in bits
    * -> If digits are less, prepend with 0 on MSB side.
    * 
    * For -ve decimal numbers
    * -> Ignore the sign and convert to binary by above methods
    * -> Fit in bits like +ve numbers
    * -> Store the 2s compliment of this binary number 
    */

   short int y = 9999999999999999;
   cout << y;


}