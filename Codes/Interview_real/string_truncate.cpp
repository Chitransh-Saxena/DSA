#include <iostream>
#include <string>
#include <regex>

using namespace std;


string makeString(char c, int n)
{
    string ans = "";
    for(int i = 0; i<n; i++)
    {
        ans+=c;
    }

    return ans;
}

string getString(string s, int n)
{
    int count = 0;

    for(int i = 0; i<s.size(); i++)
    {   
        string temp = makeString(s[i], n);
        if(s.find(temp) != string::npos)
        {
            s.replace(i, n, "");
            i = i-1;
            count += 1;
        }
    }

    return s;
}

string getStringWithRegex(string s, int n)
{
    int count = 0;

    for(int i = 0; i<s.size(); i++)
    {   
        int curr = i;
        string temp = makeString(s[i], n);
        if(s.find(temp) != string::npos)
        {   
            regex r(temp);
            s = regex_replace(s, r, "");
            i = curr;
            count += 1;
        }
    }

    return s;
}

string getAns(string A, int B)
{
    int i=0;
    while(i<A.size())
    {
        int cnt=1;
        char ch=A[i];
        for(int j=i+1;j<A.size();j++)
        {
            if(A[j]==ch)
            {
                cnt++;
                if(cnt==B)
                {
                    A.erase(A.begin()+i,A.begin()+j+1);
                    i--;
                    break;
                }
            }
            else
            {
                break;
            }


        }
        i++;
    }

    return A;
}




int main()
{
    // string str;
    // cin >> str;

    // int num;
    // cin >> num;

    // cout << getStringWithRegex("abcddcbsa", 2) << endl;

    cout << getAns("abcddcbsa", 2) << endl;

}