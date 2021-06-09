/*

CRITICAL CONCEPT HERE - When we do inorder traversal of a binary search tree, we get a sorted array
And the middle element of that sorted array is the root of the entire tree

*/

TreeNode* sortedArrayToBSTHelper(int l, int r, vector<int>& nums)
    {
        if(l > r)
            return NULL;
        
        int mid = l + (r-l)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper( l, mid-1, nums);
        root->right = sortedArrayToBSTHelper( mid+1, r, nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
       if(nums.size() == 0)
           return NULL;
        
        /*
            Main concept which drives the solution of this question is - Inorder traversal of a binary search tree provides us a sorted array
            So now, we have to find the root, and start placing elements to its left and right
        */
        
        TreeNode* root = NULL;
        root = sortedArrayToBSTHelper(0, nums.size()-1, nums);
        
        return root;
    }