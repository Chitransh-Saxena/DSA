/*
        Brute Force approach would be to get all the substrings of S1 and S2.
        And among them, check one by one.
        -> But that will be having a complexity of O(n^5)
        
        Optimized approach would be, to generate a DP table
        -> We can consider string S1 = ABCDGH and S2 = ACDGHR
        
        -> We can compare the prexis one by one of all the substrings here
        -> Substrings of S1 = A, AB, ABC, ABCD, ABCDG, ABCDGH, B, BC, BCD, BCDG, BCDH ....
        -> Similarly we get all substrings of S2
            -> NOTE: We do not actually have to calculate the substrings of S1 and S2
            -> We just need to do an on the go comparison, which will store the result in a table
            -> So, when we go to next substring, we only have to compare the last characters, and for the remaining string
                -> The result can be fetched from the table itself
    
    */
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        
        int DP[n+1][m+1];
        int ans = 0;
		
		for(int i = 0; i<=n; i++)
		{
		    for(int j = 0; j<=m; j++)
		    {
		        // We leave one row and one column blank because we have to consider [], blank subarray as one of the possibility too
		        // For, this, we mark first row and first column as totally 0
		        if(i == 0 || j == 0)
		        {
		            DP[i][j] = 0;
		        }
		        
		        // If last character of the current substring is same, we compare the second last characters now
		        else if(S1[i-1] == S2[j-1])
		        {
		            DP[i][j] = 1 + DP[i-1][j-1];
		        }
		        else
		            DP[i][j] = 0;
		            
		            
		        ans = max(ans, DP[i][j]);
		    }
		}
		
		return ans;
	    
    }