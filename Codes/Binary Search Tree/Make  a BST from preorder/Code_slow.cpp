#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
   
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size()<=0) {
            return NULL;
        }
        // First element of the vector is the root element
        // Preorder traversal is root, left, right
        
        int root_item = preorder[0];
        vector<int> smaller_elems, greater_elems;
        
        for(int i = 1; i<preorder.size(); i++) {
            
            if(root_item > preorder[i]) {
                smaller_elems.push_back(preorder[i]);
            }
            else {
                greater_elems.push_back(preorder[i]);
            }
        }
        
        // Rule of Pre-Order is that first root is traversed, left subtree and  then right subtree
        // So first create a node with data, make it's left subtree/node, then make it's right
        // Also, since the vector is given in a pre-order fashion, this approach works
        // In case of inorder, below lines just need to shuffled a little bit
        TreeNode* root = new TreeNode(root_item);
        root->left = bstFromPreorder(smaller_elems);
        root->right = bstFromPreorder(greater_elems);
        
        return root;
        
    }
};