#include <iostream>
#include <string>

using namespace std;

int freqOfSubstring(string str, string sub)
{
    int in = str.find(sub);
    int count = 0;


    if(in != std::string::npos)
    {
        count+=1;
        for(int i = in+1; i<str.size(); i++)
        {

            str = str.substr(i, str.size()-1);
            int t = str.find(sub);
            if(t != std::string::npos)
            {
                count+=1;
                i = t+=1;
            }
        }
    }

    return count;
}

int main()
{
    cout << freqOfSubstring("manmandiman man woman", "man");
}


