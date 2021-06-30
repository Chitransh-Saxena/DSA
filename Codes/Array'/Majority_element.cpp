#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



// Brute Force Approach - 1
int majorityElement(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    int count = 1;
    
    for(int i = 1; i<n; i++)
    {
        if(nums[i] == nums[i-1])
        {
            count+=1;
        }
        else
        {
            if(count > (n/2))
            {
                return nums[i-1];
            }
            else
            {
                count = 1;
            }
        }
    }
    
    return nums[n-1];
}

// Minutely optimized approach - 2

int majorityElement(vector<int>& nums) {
        
    map<int, int> f;
    
    for(int i = 0; i<nums.size(); i++)
    {
        f[nums[i]]+=1;
        
        if(f[nums[i]] > (nums.size()/2))
        {
            return nums[i];
        }
    }
    
    return 0;
}

/*
    Moore's Voting Algorithm

    NOTE: This algorithm will ONLY work if there is absolutely an element which appears more than n/2 times
    The idea is, we pick first element, and assume it is the majority one, and keep increasing count
    The moment we see other elements, we start reducing the count by 1.
    The moment count reaches 0, we make the current element as our majority element

    The algorithm says, at the end, whichever element stays in that variable, will be the one which is majority element

    TODO: I still do not understand the intuition behind this. Logic is clear, working is super easy, intuition, not so clear
*/

int majorityElement(vector<int>& nums) {
    
    int count = 0, el = 0;
    int n = nums.size();
    
    for(int i = 0; i<n; i++)
    {
        if(count == 0)
        {
            el = nums[i];
        }
        

        if(nums[i] == el)
            count+=1;
        else
            count -=1;

    }
    
    return el;
}