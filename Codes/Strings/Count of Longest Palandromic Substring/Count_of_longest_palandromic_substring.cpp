#include <iostream>

using namespace std;


/*
    Look at the code of count, for basic logic
*/

int countSubstrings(string s) {
        
        string s1 = s;
        string s2 = s;
        
        int n = s.size();
        
        int count = 0;
        
        int DP[n+1][n+1];
       
        /*
            -> We cannot do standard i->n, j->n DP approach here, because that will not fill up the table in a manner we want
            -> We want, to first handle all the single character substrings
                -> Then all the 2 character substrings
                -> This way, we will have our basic trivial cases solved, which can generate answer for futrue cases
                
            -> So, we use a third variable "gap" to measure gap between 2 characters
        */
        
        
        for(int gap = 0; gap <n; gap++)
        {
            for(int i = 0, j = gap; j<n; i++, j++)
            {
                if(gap == 0)            // Strings of only 1 char
                    DP[i][j] = 1;
                
                else if(gap == 1)       // Strings of only 2 char
                    if(s1[i] == s2[j])            
                        DP[i][j] = 1;
                    else
                        DP[i][j] = 0;
                
                else                    // There are more than 1 or more characters in between first and last character
                    if(s1[i] == s2[j] && DP[i+1][j-1] == 1)
                        DP[i][j] = 1;
                    else
                        DP[i][j] = 0;
                
                
                if(DP[i][j] == 1)
                    count+=1;
                
            }
        }
        
        return count;
            
    }