int removeDuplicates(vector<int>& nums) {
       
        if(nums.size() == 0)
            return 0;
        
        int index = 1;
        
        // Basically, we move all the unqiue elements to the front
        // Since we have to return the size of new array, we basically return the 'index'

        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[index++] = nums[i];
            }
        }
        
        return index;
        
    }