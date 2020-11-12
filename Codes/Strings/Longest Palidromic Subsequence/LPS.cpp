/*
Longest Palindromic Subsequence:

Given a string, find the Longest Palindromic Subsequence.

Example - BBBAB
Here LPS will be BBBB (NOTE that we are finding subsequnce and not substring, so sequence matters, though it can be discontinues)

Approach - 
To find the longest palindromic subsequnce, we have the find a subsequence which is common from both forward and backward directions.

So, that makes this problem as simple as taking LCS of string and reverse of that string.

*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len1 = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        int len2 = rev.length();
        
        // Making a DP matrix to store the length of LCS
        // Making 1 extra r,c for the blank subsequence
        int dp[len1+1][len2+1];
        
        // Fill last row and column with 0 (empty string is of length 0)
        for(int i = 0; i<=len1; i++) {
            for(int j = 0; j<=len2; j++) {
                dp[i][j] = 0;
            }
            
        }
        
               
        // Going to follow bottom up approach
        // Will start populating the DP matrix from second last r,c, because last r,c will be blank
        for(int i = len1 - 1; i>=0; i--) {
            for(int j = len2 - 1; j>=0; j--) {
                char c1 = s[i];
                char c2 = rev[j];
                if(c1 == c2) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
        
    }
};