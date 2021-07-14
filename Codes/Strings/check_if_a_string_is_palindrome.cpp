#include <iostream>
#include <string>

bool isPalandrome(std::string s)
{
    int l = 0, r = s.size() - 1;
    while(l<=r)
    {
        if(s[l++] != s[r--])
            return false;
    }
    return true;
}

int main()
{
    if(isPalandrome("aabcaa"))
        std::cout << "String is palandrome\n";
    else
        std::cout << "Not palandrome\n";
}