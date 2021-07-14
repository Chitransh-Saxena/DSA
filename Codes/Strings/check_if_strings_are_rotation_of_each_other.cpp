#include <iostream>
#include <string>

bool isRotation(std::string s1, std::string s2)
{
    // abcd dabc

    // abcdabcd

    // If we want to check that if s2 is rotation of s1, we can create a temp string s1+s1 and check if s2 is substring of that

    std::string temp = s1+s1;

    if(temp.find(s2) != std::string::npos)
        return true;
    else
        return false;
}


int main()
{
    std::string s1 = "abcd";
    std::string s2 = "dabc";

    if(isRotation(s1, s2))
        std::cout << "Yes, rotation\n";
    else
        std::cout << "No rotation\n";
}