/*
Depth First Search have 3 variants - Inorder (left->root->right)
Inorder traversal of a tree - left->root->right
*/

void traverseInorder(Node* root) {
		
	if(!root) {
		return NULL;
	}
	
	traverseInorder(root->left);
	cout << root->data << "\n";
	traverseInorder(root->right);	
}