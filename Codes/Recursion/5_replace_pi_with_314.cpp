#include <iostream>


// This does not replace the actual string, it just prints in the place of that
void makeString(std::string s)
{

    if(s.size() == 0)
    {
        return;
    }

    // Because we are gonna make sure that the substring that we are dealing with has these two in it's first pair of chars
    if(s[0] == 'p' && s[1] == 'i')
    {
        std::cout << "3.14";
        makeString(s.substr(2));
    }
    else
    {
        // If not pi, we are gonna print 1 character, and check the next character
        std::cout << s[0];
        makeString(s.substr(1));
    }
}


int main()
{
    std::string str = "piajbndjpiabcdefghpi";
    std::cout << "Original String = " << str << std::endl;

    makeString(str);
    std::cout << "\nAfter replacing pi with 3.14 = " << str << std::endl;
}