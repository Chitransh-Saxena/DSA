/*
        Keep one pointer for non-zero elements, it will basically count the number of non zero elements
        Now, once we know how many 0s are there, we can basically put those many 0s from index->size()-1
    
    */
    
    
    void moveZeroes(vector<int>& nums) {
        
        
        int index = 0;
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {
                nums[index++] = nums[i];
            }
        }
        
        for(int i = index; i<nums.size(); i++)
        {
            nums[i] = 0;
        }
    }