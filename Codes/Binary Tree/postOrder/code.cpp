/*
Traverse the tree in this manner - Left->right->root
*/

void postOrderTraversal(Node* root) {
	
	if(!root) {
		return NULL;
	}
	
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
	
}
