/*
    Given an array of numbers, find the length of the longest consecutive sequence of numbers

    Approach 1:
        -> Noob approach, without thinking much, this one worked fine
            -> Sorting does the time complexity of O(nlogn).
            -> Iterating once again for O(n)

    Approach 2:
        -> Hashing, in this approach, we can put all the elements in 1 set (this will give us unique ones)
        -> Then just do the count from there
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    
    if(nums.size() == 1)
        return 1;
    
    if(nums.size() == 0)
        return 0;
    
    sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    
    int ans = 0;
    
    int curr = 1;
    for(int i = 1; i< nums.size(); i++)
    {
        if(nums[i] == (nums[i-1] + 1))
        {
            curr+=1;
        }
        else
        {
            curr = 1;
        }
        
        ans = max(ans, curr);
    }
    
    ans = max(ans, curr);
    
    return ans;
    
}

/*
    In this approach, we put the elements into one set
    -> Then we traverse the vector, and for each element, we check if any smaller element exists (n-1)
    -> If not, then this could be potentially start of the longest sequence
        -> So, we make a while loop, and get the counter

*/

int longestConsecutive2(vector<int>& nums) {
        
        if(nums.size() == 1)
            return 1;
        
        if(nums.size() == 0)
            return 0;
        
        set<int> s;
        
        for(int i = 0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        
        int count = 1;
        int ans = 0;
        
        
        for(int num: nums)
        {
            if(!s.count(num - 1))
            {
                count = 1;
                int curr = num;
                while(s.find(curr+1) != s.end())
                {
                    curr+=1;
                    count+=1;
                }
                
                ans = max(ans, count);
            }
            
            
        }
        
        return ans;
        
    }