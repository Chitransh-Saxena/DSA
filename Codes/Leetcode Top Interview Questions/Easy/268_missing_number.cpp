/*
One approach could be to sort the array and check if the index is matching with the numebr
But this is linear approach.

O(1) - space
O(n) - time

*/


int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int expected_sum = (n * (n+1))/2;
        
        int sum = 0;
        for(int x: nums)
        {
            sum+=x;
        }
        
        return expected_sum - sum;
    }