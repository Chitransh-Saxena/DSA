/*
    Given an array of integgers (+ve and -ve)
    Find the max sum that can be formed by contigous subarray (array elements have to be in sequence and form the largest sum)

    Approach - 

    -> Basic approach
        -> init ans = INT_MIN and sum = 0
        -> Now sum will be sum += current array element
        -> So, for answer we take max of answer so far and sum so far
        -> Once we have answer for current iteration, we also make sure that sum for next iteration is >=0, otherwise negative will deprecate the value
*/


int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int ans = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i<n; i++) {
            
            sum +=arr[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
        
    }