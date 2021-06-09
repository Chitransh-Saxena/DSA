/*
    A vector has all elements twice but only one element occurs once, find that
*/

int singleNumber_1(vector<int>& nums)
{
    
    set<int> s;
    
    for(int i = 0; i < nums.size(); i++)
    {
        if(s.find(nums[i]) == s.end())
            s.insert(nums[i]);
        else
            s.erase(nums[i]);
    }
    
    return *s.begin();
}


int singleNumber_2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int count = 1;
        for(int i = 1; i<nums.size(); i++) {
            
            if(nums[i] == nums[i-1]) {
                count+=1;
            }
            else {
                if(count == 1) {
                    return nums[i-1];
                }
                
                if(count > 1) {
                    count = 1;
                }
            }
        }
        // If single element has not been found till now, last element is the only possibility. We are saying this under the assumption that we will always have a single element.
        return nums[nums.size()-1];
    }

