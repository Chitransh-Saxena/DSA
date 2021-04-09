/*

This is O(n2) solution, this can be done in O(nlogn).

Why to take LIS till nums[i]?
--> Because the compulsion that DP[i] should be populated by LIS which ends at nums[i], makes the calculation a bit simpler.
	--> Compare if nums[i] is greater than which nums[i] is greater than which elements in nums[0->i]
	--> Whichever is greatest till nums[i], DP[i] will be 1 + DP[greatest till i]

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0) {
            return 0;
        }
        int lis[n];
        
        // Going to make a array which is going to contain length of LIS till that number
        // Example - {1,3,2,6,0,8} - So, at lis[3], I will fill LIS of {1,2,3,6}. Added an extra clause that LIS should end with lis[3].
        // So, in generic approach, populating a DP array lis[i], which will contain LIS till nums[i].
        // This approach will help us in populating the DP array in a simpler way.
        // This is not memoization, this is tabulization
        
        lis[0] = 1;     //A single element is LIS of length 1
        
        for(int i =1; i<n; i++) {
            int max = 0;
            
            for(int j = 0; j<i; j++) {  				//This second loop makes it O(n^2)
                
                if(nums[i] > nums[j]) {
                    if(lis[j] > max) {
                        max = lis[j];
                    }
                    
                }
            }
            lis[i] = max+1;
        }
        
        return *max_element(lis, lis+n);
        
    }
};
*/