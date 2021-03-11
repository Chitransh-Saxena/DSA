/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    int max_node(TreeNode* root) {
        if(root->right) {
            return max_node(root->right);
        }
        else {
            return root->val;
        }
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) {
            return NULL;
        }
        
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Is it a leaf node?
            if(!root->left && !root->right) {
                return NULL;                    // If root is the elment that we want to remove and it has no child, return NULL in place of this node.     
            }
            else if(root->left && root->right) {    // It has both left and right node.    
                
                // Here, we have found the element that we want to remove but it has both left and right node.
                // So, we will just take the maxmimum (right node) and replace with this node.
                // This will remove the required element, and since we are replacing with it with a larger element, it will keep in check of BST property
                // NOTE: Replacing with max of subtree is in check with the BST property, because right child is greater than parent.
                
                // Also, we are considering that there could be an entire subtree of of elements from out current element, so we are looking at great deal of adjustments
                
                int lmax = max_node(root->left);        // get the max element of the left side, because since it is from the left side, all other elements on left would still be smaller and on the elements on right would anyway remain greater
                
                root->val = lmax;
                root->left = deleteNode(root->left, lmax);     // Now we are giving head as root->left and removing the node with data as lmax, because we already assigned lmax to another node just now
                
                return root;
                
            }
            else if (root->left) {          // So if current node which we want to remove has only left child
                return root->left;          // We return the left child, so now, it's grandparent will connect to this instead of the current node (which we wanted to remove)
            }
            else {
                return root->right;         // Same funda as above for this case too.
            }
        }
        return root;
    }
};