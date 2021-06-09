#include <iostream>

void revertString(std::string &s, int l, int r)
{
    if(l>r)
        return;
    
    std::swap(s[l], s[r]);

    revertString(s, l+1, r-1);
}

// A different method, which does not alter the string, just prints the reverse of the string
void printReverse(std::string s)
{
    if(s.size() == 0)
        return;
    
    std::string rest_of_string = s.substr(1);       // Fetch the remaining string apart from first character

    printReverse(rest_of_string);                   // Call recursively for the rest of the function

    // After each recursive call, we are removing the first character, so, at the end there will be only last character
    // First that will be printed, then control will go to second last call, where the string has only 2 characters, then second last character will be printed
    // This way, all the characters from the end will be printed

    // -_- Just wondering why didn't we just traverse from the end and had fun with it -_-
    std::cout << s[0];                       

}

int main()
{
    std::string s = "Noname";

    std::cout << "Reverse of " << s << " = ";
    revertString(s,0, s.size()-1);
    std::cout << s << std::endl;


    std::string a_string = "A name";
    printReverse(a_string);
}