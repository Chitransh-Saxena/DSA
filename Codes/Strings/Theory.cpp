#include <iostream>
#include <string>

/*
    Character Arrays - 
        -> Size needs to be known before hand
        -> Larger size required for operation
        -> No terminating extra character
    
    Strings -
        -> No need to know size before hand
        -> Operations can be performed in a easier way
        -> Terminated with special character '/0'
*/

int main () {

    std::string s0;
    std::cout << "Enter a sentence with spaces\n";
    std::cin >> s0;     // Takes only first word, doesn't take after first word

    std::cout << s0 << "\n";

    std::string s;
    getline(std::cin, s);   // With this, we can have the entire sentence with spaces from the input stream
    std::cout << s;

    std::string c = "abc";
}

