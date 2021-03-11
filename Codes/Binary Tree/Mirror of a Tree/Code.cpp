/*
	Mirror of a Tree - Given a tree, create a binary tree which is mirror image of the tree.
	How is it mirror? - This can be understood by inorder traversal of the tree.
	
	Understanding why the question is not tough - We just have to swap the left and right node of each parent node.
	Approach - Start by reaching the end of the tree, then start swapping left and right by using basic tmp node method. (Would be more clear when solution is there)
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root) {
            return NULL;
        }
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        // If it came here, we are probably done with either side of a tree, and start inverting elements
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        
        return root;
        
    }
};