/*

Preorder - Root->left_right.
*/

void traversePreOrder(Node* root) {
	
	if(!root) {
		cout << root->data << " ";
		traversePreOrder(root->left);
		traversePreOrder(root->right);
	}
}