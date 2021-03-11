/*
 Following the basic logic that if the element is greater than root, it has to go to left, else it has to go to right.
 Following this approach recursively.
*/



Node* insert(Node* root, int key)
{

    if(root == NULL) {                  // While recursing, if we reach the leaf node, we create a new node and return
        Node* x = new Node(key);        // The code's logic will automatically adjust it to left or right.
        return x;
    }
    
    if(key > root->data) {                          // This if else is a basic logic of if the element is greater, add it to right, else add it to left.
        root->right = insert(root->right, key);
    }
    else if(key < root->data){
        root->left = insert(root->left, key);
    }
    else {}                                         // In case of equality, do nothing.

    return root;
}