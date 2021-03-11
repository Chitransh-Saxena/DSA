/*
The approach used in this code was almost same as standard kadane's algorithm, but with a catch.
If the array is something like this {1,-2,-3}, standard kadane would work.
But if the array is something like this {1,-2,-3, 2}, then kadane would give ans as 2, but our answer is 3(because ciruclar array)
Now, to for this solution,
1. Take kadane of original array
2. Take sum of original array
3. Take kadane of inverted array,
If the circular array is giving higher answer, that would be reflected like this - 
arr_sum += kadane(inverted_array);


Logic Used: For circular array, we need to find the sum of contributing elements.
We basically find out the sum of non-contributing element and subtract that from total sum. 
To get the sum of non-contributing elements, we simply do kadane of inverted array.
array-sum - (-max subarray sum of inverted array) 


*/
 
class Solution {
public:
    int kdane(vector<int> v){
        int ans = INT_MIN;
        int a = 0;
        for(int x: v){
            a+=x;
            ans = max(a, ans);
            a = max(a, 0);
        }
        return ans;
        
    }
    int maxSubarraySumCircular(vector<int>& A) {
        
        
        
        int max_kdane = kdane(A);    //Fetch max sum using standard Kdane's Algorithm
        int arr_sum = 0;
        vector<int> b;
        
        for(int i: A){
            arr_sum+=i;			//Get the sum of original vector
            b.push_back(-i);		//Get a vector of inverted signs
            
        }
        
        arr_sum = arr_sum + kdane(b);		
        if(arr_sum == 0){			//Standard code fails if all values are negative
            return max_kdane;			
        }
        
        return (arr_sum > max_kdane)?arr_sum : max_kdane;
        
        
    }
    
};