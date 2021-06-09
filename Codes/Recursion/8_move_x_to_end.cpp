/*
    We are given a string, we have to move the 'x' in the string to the end of the array
    axxbxxcxx -> abcxxxxxx
*/

#include <iostream>

using namespace std;

string moveChar(string s, char check)
{
    if(s.size() == 0)
        return "";

    char c = s[0];

    string ans = moveChar(s.substr(1), check);

    if(c == check)
    {
        return ans+c;
    }
    else
    {
        return c+ans;
    }
}

int main()
{

    string s = "axxbxxcxx";
    cout << moveChar(s, 'x') << endl;
}

