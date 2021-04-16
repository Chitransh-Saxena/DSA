#include <iostream>

using namespace std;

int main () {


    string a = "badzkhh";

    // If we want to store the characters 'a', 'b', 'c' .... as 0, 1 ,2

    int index_we_wish_to_change = 5;
    int i = a[index_we_wish_to_change] - 'a';           // For 'b', this will give 1, for 'a', it will ive 0 ... so on



    // Now, if we want to convert from index to character again
    char c = (char)(i + 'a');           

}