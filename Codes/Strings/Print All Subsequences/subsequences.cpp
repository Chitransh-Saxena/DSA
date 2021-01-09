#include <iostream>
#include <string>

#define ll long long int;

using namespace std;

int main () {

    char s[200];    // Declaring a character array and giving it a size of 200
    cin >> s;
    int n = strlen(s);  // Calculating the size of the input given by user

    // 2^n -1 subsequences
    // 2^n can by calculated by 1 << n...

    int num_of_subsequnces = (1 << n) - 1;
    cout << "{}\n";

    // Iterating for each subsequence now
    for(int i = 1; i<=num_of_subsequnces; i++) {

        int temp = i;
        int j = 0;

        // temp is used because we will be using the 'i' value to see which bit we will be operating on. Once our operation is done, we will change it's value, thus using temp
        // so that it does not change the original value
        while(temp > 0) {
            if(temp&1) {        // Checking if the last bit is set. More like 
                cout << s[j] << " ";
            }
            j++;
            temp = temp >> 1;       // Unset the last bit because we have seen it, so now we will not use the same combination of 0 and 1 again (removing used sequence)
        }
        cout << "\n";
    }
}