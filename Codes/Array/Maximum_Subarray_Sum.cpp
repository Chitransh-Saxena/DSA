int maxSubarraySum(int arr[], int n){
        
        int ans = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i<n; i++)
        {
            sum+=arr[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        
        return ans;
    }