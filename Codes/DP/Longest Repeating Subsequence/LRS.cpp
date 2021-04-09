/*
Longest Repeating Subsequence :
In a given string, find a subsequence, that is repeated in the same string, but same characters if counted in subsequence 1, cannot be counted in subsequence 2.

Example - AABEBCCDD
Here, we can ABD is subsequence that is coming at position (0,2,7) and ABD is another subsequence coming at (1,4,8). All indices of each character are different.

Subsequence - Repeating this defintion even though it is there in other questions, it is a part of string, where sequence of characters matter, even though they can be discontinues.

Basic Approach - 

In the above example, we can clearly see that the elements that are coming once are defintely not counted in the output.

But if we want to solve this problem in even shorter way, we can try a DP approach.

Write the String twice, 

AABEBCCDD
AABEBCCDD

We will treat them as string 1 and string 2.
If we take LCS of str1 and str2, it will be AABEBCCDD

But our output is supposed to be ABD, so what has to change?
Well, according to question, if our output has A in it, we are expecting A to be coming from 2 different indices.
so, we can straight away say, if A is coming from str1[i] and str2[j], i should not be equal to j.
This condition will also remove the single elements like E and C from this output.

Thus making our output as ABD.

In short, the solution to Longest Repeating Subsequence is LCS with a condition of i!=j.


*/

#include <bits/stdc++.h>

using namespace std;

int LRS(string s) {
    int l1 = s.length();
    
    string ss = s;
    int l2 = ss.length();
    
    int dp[l1+1][l2+1];
    for(int i = 0; i<=l1; i++) {
        for(int j = 0; j<=l2; j++) {
            dp[i][j] = 0;
        }
    }
    
    for(int i = l1-1; i>=0; i--) {
        for(int j = l2-1; j>=0; j--) {
            char c1 = s[i];
            char c2 = ss[j];
            
            if(c1 == c2 && i!=j) {      // Extra condition in the  code of LCS
                dp[i][j] = dp[i+1][j+1] + 1;
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main()
 {
	int t;
	cin >> t;
	
	while(t>0) {
	    t--;
	    int n;
	    cin >> n;
	    string str;
	    cin >> str;
	    
	    cout << LRS(str) << "\n";
	    
	}
	return 0;
}