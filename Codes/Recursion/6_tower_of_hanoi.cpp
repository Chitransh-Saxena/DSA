#include <iostream>

// STILL CANNOT DO IT. STILL CANNOT VISUALIZE THE SOLUTION ALONG WITH THE CODE RUNNING IN MY MIND. DEBUGGING DID NOT HELP EITHER

/*
    Have to shift blocks from Stand A to stand C.
    Can only shift one at a time
    Cannot keep bigger on the top of smaller


    Approach - 

    From source, we have to find a way to put it in destination
    Put another in helper (Rod B)

    Now, we can 
*/


void towerOfHanoi(int n, char src, char destination, char helper)
{
    if(n == 0)
        return;

    // We want to send n-1 rods from source to helper, where destination rod serves as a helper
    towerOfHanoi(n-1, src, helper, destination);
    std::cout << "Move from " << src << " to " << destination << "\n";

    // Now, we send n-1 blocks from helper to destination where src acts as the helper rod
    towerOfHanoi(n-1, helper, destination, src);


}

int main()
{
    towerOfHanoi(3,'A', 'C', 'B');
}

