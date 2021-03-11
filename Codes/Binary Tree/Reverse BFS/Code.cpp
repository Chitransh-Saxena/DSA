vector<int> reverseLevelOrder(Node *root)
{
	// This question was similar to last one, but instead of storing in vector, I stored in a stack in reverse order
	// And then put it into a vector, it was my first guess, but it worked in first trial.
	
	
	queue<Node*> q;		// Queue to keep track of nodes at each level
	q.push(root);		// Init the queue with root element, thats where we will start our traversal from
	
	vector<int> v;		// To store the elements at each level, we can print them later
	
	stack<int> s;
	
	
	while(!q.empty()) {
		
		int sz = q.size();		// We store the queue size for further iteration, if we directly use q.size() in for loop for end, it will give us wrong answer because queue size will be increasing as we will be adding elements of each level
		
		for(int i = 0; i<sz; i++) {
			Node* curr = q.front();		// Store front element of the queue in a temp element;
			q.pop();					// Removal because we will removing elements of this level in this for loop
			
			s.push(curr->data);
			
			if(curr->right) {
				q.push(curr->right);
			}
			if(curr->left) {
				q.push(curr->left);		// We have added the elements to the queue, but this will be reflected when this for loop ends, and it begins from 0 again, because this time number of iterations is the number of elements in this level.
			}
		}
	}
	
	while(!s.empty()) {
	    v.push_back(s.top());
	    s.pop();
	}
	return v;
}