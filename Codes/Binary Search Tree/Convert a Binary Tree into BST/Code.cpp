/*
    Given a Binary Tree
        
        1. Traverse the tree and input it's data into a vector
        2. Now sort the vector, because inorder traversal of a BST is a sorted vector.
        3. So we know that if we build a tree from this vector's elements, we can build a BST
        4. So, we will just do inorder traversal of the Binary Tree and compare and replace the elements with the sorted vector.
        5. Comparison and replacement are key parts of this solution, so using pass by reference for iterator to do comparison
*/

void makeVector(Node* root, vector<int> &v) {
    
    if(!root) {
        return;
    }
    
    makeVector(root->left, v);
    v.push_back(root->data);
    makeVector(root->right, v);
}

void makeBST(Node* root, vector<int> &v, int &i) {
    
    if(!root) {
        return;
    }
    
    makeBST(root->left, v, i);
    root->data = v[i++];
    makeBST(root->right, v, i);
}


Node *binaryTreeToBST (Node *root)
{
    if(!root) {
        return NULL;
    }
    
    // Store the tree elements in any container
    vector<int> v;
    makeVector(root, v);
    
    // Sort the elements, because in inorder fashion, in BST, items will be sorted
    sort(v.begin(), v.end());
    
    // Now replace the items in the node with vector elements in that sequence, that is why 'i' iterator is passed by reference
    int i = 0;
    makeBST(root, v, i);
    return root;
}