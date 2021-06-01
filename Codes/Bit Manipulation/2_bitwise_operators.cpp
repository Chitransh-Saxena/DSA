#include <iostream>

using namespace std;

int main () {


    // 1. Not operator - ~ .It is a unary operator. Unary means we can use this operator with only 1 operand
    // This will flip the bits. 010 will become 101
    // NOTE: In case of unary operand, since it flips the binary digits, it can sometimes cause overflow of value and thus produce undesired results
    // So, be careful about it
    int x = 6;
    x = ~x;

    
    // 2. AND operator - & .It gives binary when both binary digits are 1
    // 1&1 = 1, 1&0 = 0, 0&1 = 0, 0&0 = 0
    int a = 15, b = 6;
    int c = a&b;    // This will convert 5 and 6 to binary, do & amongst both numbers and produce the result

    cout << c << "\n";      // This produces 4

    // 3. OR operator - | .It gives 1, when any of the operand is 1.

    int d = a|b;
    cout << d << "\n";

    // XOR operator - ^ .Produces 1 if two operands are different.
    int e = a^b;
    cout << e << "\n";

    // Left Shift operator - << .
    // 5 << 1. Here, in the binary representation of the number, all the bits are shifted by 1 and 0 is appended at the end.
    // This is also a shortcut for multiplication by 2.
    // Therefore, we can conclude, n << 1 = n * 2;
    int k = 25;
    k = k << 1;
    cout << k << "\n";

    // Right Shift operator - >> .
    // All the bits are shifted to right hand side, and appropriate number of 0s are prepended in the number
    // 5 >> 1. This is also division by 2.
    k = k >> 1;
    cout << k << "\n";


}