/*
    In a BST, the root is greater than maximum of left_subtree, and smaller than minimum of right subtree.
    1. So we straight away choose the mid element as the root.  (MAJOR ASSUMPTION)
    2. We build left subtree with elements on left half of vector, and right subtree with elements on right half of the vector.
    3. One more point that this approach creates a height balanced BST, how?
*/

class Solution {
    
    TreeNode* makeBST(vector<int> v, int start, int end) {
        
        // left_index cannot be greater than right_index
        if(start > end) {
            return NULL;    // empty node in this case
        }
        
        // Get the root element
        // In case of even values, this gives value to right of the mid
        int mid_elem = start + (end - start)/2;
        TreeNode* root = new TreeNode(v[mid_elem]);
        // All elems to left of mid are smaller, so they go in left_subtree, we passing indices of first half of vector to left node
        root->left = makeBST(v, start, mid_elem -1);
        
        // Greater elems (after mid) go to right subtree, so passing indices of right half of vector to right node
        root->right = makeBST(v, mid_elem + 1, end);      
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size()<=0) {
            return NULL;
        }
        
        // When a vector of sorted values is given, we know if we do inorder traversal of that tree, it will give us that vector
        // So, now we just get to the middle of the vector, choose the middle element of the tree as the root.
        // How did that happen?
        // Once we have chosen the root, we can start forming left and right subtree
        
        int s = 0;
        int e = nums.size() -1;
        
        return makeBST(nums, s, e);
    }
};