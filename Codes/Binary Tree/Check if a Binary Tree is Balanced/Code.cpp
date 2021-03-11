/*
    A binary tree is said to be balanced if, at each node level, difference between left_height and right_height is not more than 1.
*/


class Solution {
    
    int height(TreeNode* root, bool &is_balanced) {
        if(!root) {
            return 0;
        }
        int lh = height(root->left, is_balanced);
        int rh = height(root->right, is_balanced);
        
        
        if(abs(lh - rh) > 1) {          // The moment we get height diff more than 1, we set this value to false;
            is_balanced = false;    
        }
        return 1 + max(lh, rh);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        
        if(!root) {
            return true;
        }
        bool is_balanced = true;
        int h = height(root, is_balanced);
        return is_balanced;
    }
};