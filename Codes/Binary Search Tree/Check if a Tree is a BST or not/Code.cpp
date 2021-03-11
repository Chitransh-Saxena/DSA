/*
    A BST as some basic properties
    1. For any node, left child is smaller and right child is greater
    2. Every node should be greater than all left children and smaller than all right children
    3. For any node, not more than 2 children exists

*/

class Solution {
    vector<long long int> v;
    
    void inorder(TreeNode* root) {
        
        if(root == nullptr) {
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        v.clear();
        
        // Creating a vector by doing inorder traversal, by doing that, ideally we should be getting all the elements in ascending order
        // No duplication is assumed
        inorder(root);
        
        //NOTE HERE - ++i gives runtime = 8ms, and i++ gives runtime 12ms
        for(long long int i = 1; i < v.size(); ++i) {
            
            // Just checking if the numbers are in ascending order or not
            if(v[i] - v[i-1]<=0) {
                return false;
            }
        }
        return true;
        
    }
};