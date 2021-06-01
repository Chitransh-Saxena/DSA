#include <iostream>

int getVal(int a, int b) {

    while(a && b) {     // Our operations are gonna shift the bit, so we are gonna make sure that none of the numbers become 0

        


    }
}

int main () {

    // a|X = b.
    // How many X are there?
    // Example - 2|1 = 3 and 2|3 = 3. So, there are 2 values of 3.

    // What we know from this problem is, X is always gonna be from 1 till b.


    int a = 2, b = 3;
    int count = 0;


    // This is a brute force method
    for(int i = 1; i<=b; i++) {

        int tmp = a|i;
        if(tmp == b) {
            count+=1;
        }

    }
    std::cout << count << "\n";

    // Efficient Way
    // Convert 'a' to binary, example a = 2. So, a = 010
    // Convert 'b' to binary, example b = 3. So, b = 011

    // Now, we go and check on bitwise level, in how many ways can we convert from bit to bit via OR operation
    // 0 1 0
    // to
    // 0 1 1

    // We write down all possibilities of getting outputs in binary operation of OR
    // 0 | 0  = 0
    // 0 | 1  = 1
    // 1 | 0  = 1
    // 1 | 1  = 1

    // 0 1 0
    // to
    // 0 1 1

    // So, we know, to have 0 with OR operation of 0 with any bit (0 or 1), there is only 1 way. (Line 37)
    // To have 1 with OR operation of 1 with any bit (0 or 1), there are 2 ways. (Line 40)
    // Similarly to have 1 with OR operation of 0 with any other bit (0 or 1), there is only 1 way. (Line 38)

    // So, our answer would be 1*2*1. (Product of all possible ways of converting from bit to bit)



    // NOTE: We can also notice that if we want to convert 1|X = 0, it is not possible

}