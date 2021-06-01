#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>

#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
        
        if(s.size() == 0)
            return true;
        
        int i = 0;
        int j = s.size()-1;
        
        while(i<j) {
            
            while(i<j && !isalnum(s[i])) {
                i++;
            }
            
            while(i<j && !isalnum(s[j])) {
                j--;
            }
            
            // By now, i and j are pointing to an alnum char
            if(i<j && (toupper(s[i]) == toupper(s[j]))) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }

int main () {

    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s);
}

