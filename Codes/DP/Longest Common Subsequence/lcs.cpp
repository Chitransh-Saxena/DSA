/*
The question is, given 2 strings, find the longest common subsequence between those 2 strings.

Subsequence - In a subsequence, the order of the character matters. Example, ACBED, and CABFD, here ABD are always in same sequence (A comes first, then B and then D).
String can be discontinues in a subsequence.

Basic Approach - First find all the subsequences of String 1, match it with all subsequences of String 2. The longest string with most common chars in sequence will be the answer.

Now, point to be noted that this basic approach will fail for strings with longer length, because for a string of length 'n', there will be 2^n subsequences possible.
So, for 2 strings, 2 * 2^n, we are talking about a really long for loop here.

The concept of Dynamic Programming says that if you can solve a smaller segment of a problem and that can solve the bigger chunks then it can be solved through dynamic programming.

s(abc) - This represents all the subsequences of abc.
a*s(bc) - This represents all the subsequences of bc with 'a' preprended to them.

*1 - So, basic math says - s(abc) = s(bc) + a*s(bc) { All the subsequences of bc AND all the subsequences of bc with a before them }

Now, if we have to find LCS of abc and abd, our answer in mathematical terms would be:
*2 - s(abc) * s(abd)  --> This means we are taking cartesian product of these 2 (might sound complicated, but it is basically the for loop running for string abd inside for loop running for string abc)


Based on *1, *2 becomes - 
{s(bc) * a*s(bc) } * {s(bd) * a*s(bd) } --> We did this to divide the problem into smaller chunks, so that now we can find solution and isolate it to a smaller mathematical calculation

Or this can be written as  - 

s(bc)    X   s(bd)			- 1

s(bc)    X   a*s(bd)        - 2

a*s(bc)  X   s(bd)          - 3

a*s(bc)   X   a*s(bd)        - 4

Now, if we say c1 is first character of str1 and r1 is the remaining string of str1.

We can surely say that if c1 == c2, Then our result will be lcs of 1, plus 1. Why? Because in cases 2 and 4, lcs answer will have 'a' in it, but if we are saying c1 = c2, that means both strings have a.
Thus we can just calculate lcs for remainig strings (r1, r2) and add 1 for the first character (a).
Code can be like, if(c1 == c2) { lcs(r1,r2) + 1}

If c1 is not equal to c2, then the formula has to vary a little
also, a*s(bd) = s2, and a*s(bc) = s1....so we can also state that,
case 2 - lcs(r1, s2)
case 3 - lcs(s1, r2)

We can also say,
case 1 and case 2 combined, basically say, lcs(r1, s2)
and
case 3 and case 1, basically say, lcs(s1, r2)

We want "longest" common subsequence, so we can say, that if c1 != c2, 
ans = max(lcs(s1,r2), lcs(r1,s2));



*/
#include <iostream>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        
        int len1 = text1.length();
        int len2 = text2.length();
        
        // Making a DP matrix to store the length of LCS
        // Making 1 extra r,c for the blank subsequence
        int dp[len1+1][len2+1];
        
        // Fill last row and column with 0 (empty string is of length 0)
		// This is because we are keeping this last row and column blank and saying that blank is not common with anything so lcs of blank is 0.
		// This will help us increament the value in bottom up manner.
        for(int i = 0; i<=len1; i++) {
            for(int j = 0; j<=len2; j++) {
                dp[i][j] = 0;
            }
            
        }
        
               
        // Going to follow bottom up approach
        // Will start populating the DP matrix from second last r,c, because last r,c will be blank
        for(int i = len1 - 1; i>=0; i--) {
            for(int j = len2 - 1; j>=0; j--) {
                char c1 = text1[i];
                char c2 = text2[j];			
                if(c1 == c2) {
                    dp[i][j] = dp[i+1][j+1] + 1;		// If current characters match, we go diagonally bottom right, and add 1. (What is mentioned in above theory)
                }
                else {
				// Also, we have to consider that we are traversing to left side of the column for each row, so that means, we are calculating lcs of each substring of row (s[i] and above) with whole substring of the already traversed column.
				// Say we are at 3,2 of a 4,4 matrix. So that would mean, we are getting lcs of string_concat_of_chars(s1[3]+s1[4]), string_concat_of_chars(s2[2]+s2[3]+s2[4])
				// let's say we are at some i,j where s1[i] = d and s2[j] = c { also, s1[i+1] = "blank" (1 row down) and s2[j+1] = d (1 column right)}
				// So, now we are basically taking lcs of d, cd
				// For above example, we will look at bottom or right, and get whichever is the maximum value ( truth table of these chars, d,d will be common, and d,d is i,j+1 (last column traversed while traversing same row)
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);		 
                }
            }
        }
        return dp[0][0];
        
    }
};