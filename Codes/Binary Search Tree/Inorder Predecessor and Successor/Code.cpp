/*
    It is a complicated question, not the question as such but neither mine nor the internet's approach was much clear.
    So just went ahead with gfg approach and tried understanding it as much as possible
*/


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
// Traverse the tree
// keep traversing till it is greater than some number
// When it is not greater than some number
// Set the last traversed number as pre, and next as suc
// In case of root, think later


// So basically the problem is, if the element were in the tree, what would be it's left and right children.( I guess)

if(!root) {
    return;         // Base case, return nothing in case of root is null
}

// We can use recursion to traverse each node and check if the key is lesser or greater at each level and take decisions based on that


// In case current node is the key, max of leftsubtree is pred, and minimum of right is succ
// If key is found
if(root->key == key) {      
// Why this logic of max of left and min of right?
// Because predecessor is the number just smaller than current.
// So, all the elements in left node are smaller than current
// Now we want the largest number of those numbers (just smaller than current), so we just get the max of those.
// Similar logic applies for minimum of right as well.
    
    if(root->left) {        // Fetching Max of leftsubtree
        Node* x = root->left;
        while(x->right) {         // Because maximum value of left subtree will be last right most element
            x = x->right;
        }
        pre = x;
    }
    
    if(root->right) {
        Node* x = root->right;
        while(x->left) {
            x = x->left;
        }
        suc = x;
    }
}

// If key is smaller than root (current)
if(key < root->key) {
    suc = root;                 // Not setting the value for results, but setting for recursion, which will eventually fetch results
    findPreSuc(root->left, pre, suc, key);
}

if(key > root->key) {
    pre = root;
    findPreSuc(root->right, pre, suc, key);
}