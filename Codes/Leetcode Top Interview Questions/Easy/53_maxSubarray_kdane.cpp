int maxSubArray(vector<int>& nums) {
        
        int ans = INT_MIN;                  // Intializing this to 0 makes a fuss when only negative numbers are given
        int sum = 0;
        
        for(int x: nums)
        {
            sum+=x;                         // Get the contiguous sum
            ans = max(sum, ans);            // Store the max sum till now as ans
            sum = max(sum, 0);              // Since we have negative numbers too, make sure the sum till now does not hold negative values
        }
        
        return ans;
    }