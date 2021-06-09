/*
    It is kind of a DP concept
    We can climb either 1 or 2 stairs at a time
    That means, on a certain stair (say 3), there are 2 ways of coming, either from stair 2 (climb 1 step), or stair 1(climb 2 steps)
    Now, before reaching 3, we reach 2. How many ways of reaching 2 ? (Etiher climbing 2 steps directly or climbing 2 single steps)

    So, basically we define a base case of dp[1] = 1. To reach step 1, we have only 1 move available
    dp[2] = 2. To reach step 2, we have 2 moves available (Either clibm 2 at a time, or two 1s at a time)

    So, to reach dp[3] = we just need to sum dp[1] + d[2]; (1+2 = 3). That means there are 3 ways of reaching stair 3 (1 + 1 + 1, 1 + 2, 2 + 1)

    Now, to reach dp[n], we just have to calculate which the number of ways reaching this from previous steps dp[n-1] + dp[n-2];
*/

int climbStairs(int n) {
        
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        int dp[n+1];
        
        // For climbing 1 stair, we have 1 way
        dp[1] = 1;
        
        // For climbing 2 stairs, we have 2 ways (either climb 1 or climb 2)
        dp[2] = 2;
        
        for(int i = 3; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];      // Each time either we are gonna climb by 1 or by 2. So we can be coming to ith stair by either i-1 stair or i-2 stair
        }
        
        return dp[n];
        
    }