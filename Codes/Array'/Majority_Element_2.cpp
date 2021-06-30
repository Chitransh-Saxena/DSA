#include <iostream>
#include <vector>

using namespace std;

/*
    Refer Majority Element 1 for the idea behind this approach, this is based on Moore's Algorithm Approach
    But to be honest, Hash-Map approach is much more easier to understand.

*/

vector<int> majorityElement(vector<int>& nums) {
        
    int count1 = 0, count2 = 0;
    int el1 = -1, el2 = -1;
    
    int n = nums.size();
    
    for(int i = 0; i<n; i++)
    {
        if(el1 == nums[i])
            count1+=1;
        else if(el2 == nums[i])
            count2+=1;
        else if(count1 == 0)
        {
            el1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0)
        {
            el2 = nums[i];
            count2 = 1;
        }
        else
        {
            count1-=1;
            count2-=1;
        }
    }
    
    count1 = 0, count2 = 0;
    int ans_count = 0;
    vector<int> ans;
    for(int num: nums)
    {
        if(el1 == num)
            count1+=1;
        else if(el2 == num)
            count2+=1;
    }
    
    if(count1 > n/3)
        ans.push_back(el1);
    
    if(count2 > n/3)
        ans.push_back(el2);
    
    return ans;
    
}