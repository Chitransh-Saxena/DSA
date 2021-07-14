/*
	Diameter of a Tree - It is the length of the longest path between any two nodes in a tree. (Doesn't necessarily has to pass through the root)
	Length is considered as number of edges between those 2 nodes.
	
		1
	2		3
4		5

Imagine above is a binary tree (couldn't make the arrows so use the imagination)
Diameter would be 3. (4,2,1,3) or (5,2,1,3)
Possible confusion - Number of edges between nodes 3 and 4 is 2, so how is diameter 3.....Well, the edges are 3, nodes between those 2 nodes are 2. Don't confuse edge with a node, edge is that connecting line. Node is the element.

BIGGG P.S. - Different websites have different definition of diameter, leetcode and gfg differ heavily
Approach to solution - 
	
	-> A basic approach is that we calculate diameter of the right side and diameter of the left side and get the max of it.
	-> In above approach we are not considering the root, one more thing would be to get the height of right tree + left tree + 2 (2 edges connect the root to left and right so we add 2)
	
	-> At the end we get the max of above 3
	
	-> Code for this appraoch is below but this approach has a big flaw. (will be discussed after the code)
	
	-> BELOW CODE WAS USED IN GFG, SO FOR LEET CODE CHANGE FROM "h+3" to "h+2"
	
	Code: 
	
		int height(Node* root) {
			if(root == NULL) {
				return -1;
			}
				
			else {
				int ldepth = height(root->left);
				int rdepth = height(root->right);
			
				if(ldepth > rdepth){
					return (ldepth + 1);
				}
				else{
					return (rdepth + 1);
				}    
			}
		
		}

		int diameter(Node* root) {

			if(root == NULL) {
				return 0;
			}
			// max distance between 2 nodes on lhs
			int left_diam = diameter(root->left);   
			
			// max distance between 2 nodes on rhs
			int right_diam = diameter(root->right); 
			
			
			// Max distance between left's deepest and right's deepest
			int h = height(root->left) + height(root->right);
			int max_height_from_root = h + 3;   // 2 edges connect from root to left child and right child
			
			
			// Answer has to be either left diameter, right diameter or left_height + right_hegiht + 2;
			return max(left_diam, max(right_diam, max_height_from_root));
		}
		
	-> How is the above code flawed : 
		-> It is inefficient
		-> Why is it inefficient - The recursive function calls itself, and in it's each call, we are calling another function (height) which is also recursive, making it take much longer time.
		-> Now the question arises, what can we do to reduce this recursive overhead.
		-> One way I personally thought of was creating a map of height. Someway of mapping node with it's height. But sometimes we need height with respect to it's parent and not root node. (Complicated)
		-> So, what we basically want is, height function should not fire recursion.
		
	-> Approach :
		-> Since we want height and diameter of both left and right side, we create a pair of <diameter, height>
		-> We want to avoid avoid recursion of both functions.
		-> So instead at each point (node), we return both height and diameter.
		-> And calculate the results with same max of 3 approach.
	
*/

pair<int, int> getDiaHeightPair(Node* node) {
	
	// We are expecting this function to return diameter.
	// As usual, writing base case after writing the main code.
	
	if(node == NULL) {
		
		return {0,-1};		// These 0,0 may vary based on where the code is written, leetcode and gfg differ a bit on their defitintions of diameter.
	}

	// The pair is <diameter, height>
	pair<int, int> left_ = getDiaHeightPair(node->left);
	pair<int, int> right_ = getDiaHeightPair(node->right);
	
	int diam_when_root_included = left_.second + right_.second + 3;     // Make this +2 in case of leetcode
	
	pair<int, int> val;
	// For diameter follow the max of 3 approach.
	val.first = max(diam_when_root_included, max(left_.first, right_.first));
	// For height, using the concept that this is a recursive function, so we are already having the height of previous node, since we are going one node down, height is increased by 1.
	val.second = max(left_.second, right_.second) + 1;
	return val;
}
int diameter(Node* root) {
    
    int ans = getDiaHeightPair(root).first;
    return ans;
}
