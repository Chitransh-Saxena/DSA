class Trapping_rainwter {
    
    /*
        Currently solved by a brute force approach
        
        -> Traverse the array from left to right
        -> At each point, check the left_max_height and right_max_height
            -> Whatever is the minimum of those two, the water can be stored till that level at max (can deduce this logically from pen-paper approach)
            -> Now, reduce the elevation of this current cell for which we are measuring, because whatever is the height of current cell, is already consumed and water cannot be trapped there
            
            -> So, basically the formula comes down to Math.min(l_max, r_max) - height[i];
                -> This value could go negative so make sure that is being handled
        -> One general doubt on this approach could be coming from the fact that r_max could go very high and could be at the end of the array, how is that affecting the current cell?
            -> Because the wall that is trapping water in the current cell might not be of that height
            -> Well, this is handeled by the fact that we calculate the left_max also, and take the minimum of it
    */
    
    
    public int trap(int[] height) {
        
        int ans = 0;
        
        for(int i = 0; i<height.length; i++) {
            
            // Currently the water stored would be min(left_max, right_max) - height[i]
            int l_max = 0;
            int r_max = 0;
            for(int j = i-1; j>=0; j--) {
                l_max = Math.max(height[j], l_max);
            }
            
            for(int k = i+1; k<height.length; k++) {
                r_max = Math.max(height[k], r_max);
            }
            
            int curr = (Math.min(l_max, r_max) - height[i]);
            ans += Math.max(0, curr);
        }
        
        return ans;
        
    }


    /*
        In the previous approach, we optimize what was problematic in the previous approach

        -> For l_max and r_max we were calculating via 2 for loops in each run
            -> So, in this approach, we create a prefix sum kind of array and store the max of left_height in 1 array and max of right_height in another array
        -> And, in actual calculation, we just refer to this array for l_max and r_max
            -> Then we just use original formula, and be done with it
    */


    public int trapOptimal(int[] height) {
         
        if(height.length == 0) {
            return 0;
        }
        
        int[] l_sum = new int[height.length];
        int[] r_sum = new int[height.length];
        
        l_sum[0] = height[0];
        for(int i = 1; i<height.length; i++) {
            l_sum[i] = Math.max(l_sum[i-1], height[i]);
        }
        
        r_sum[height.length - 1] = height[height.length - 1];
        for(int i = height.length - 2; i>=0; i--) {
            r_sum[i] = Math.max(r_sum[i+1], height[i]);
        }
        
        int ans = 0;
        
        for(int i = 0; i<height.length; i++) {
            
            int curr = Math.min(l_sum[i], r_sum[i]) - height[i];
            ans += Math.max(0, curr);
        }
        
        return ans;
    }
}