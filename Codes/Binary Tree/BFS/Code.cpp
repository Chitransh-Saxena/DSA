/*
Breadth First Traversal - Also called Level Order Traversal of a TREE ( It will be a little different for a graph)

1. As the name suggests, we start from the top of the tree (root)
2. And traverse the elements on each level from left to right

Approach :

-> We need a queue data structure to keep track of nodes at each level
-> So we init a queue, add root, and keep looping it till it is empty
-> Now the demand of question is to add elements in level order fashion.
-> So, we iterate for current size of the queue, in a for loop, add the data items of front() element and pop() that element
-> Why above step? That way, in that particular iteration, we have traversed the element and removed it from the queue
-> Now in same iteration, we check if the this current element that we popped has a left or right, if yes, we add it to the queue.
-> Now wouldn't that disturb the order of looping or create some sort of confusion?
-> No? Because, before starting our for loop, we fixed it's limit to queue's size at that time, although we have increased the size of queue now, but the variable in which we stored it has not changed.
-> So, once the iterations are done, we would only be left with new elements. This is one for loop.
-> We keep on doing this till our queue is finally empty (Remember we are popping in each iteration too, queue is bound to be empty sometime)

*/

vector<int> levelOrder(Node* node) {
	
	queue<Node*> q;		// Queue to keep track of nodes at each level
	q.push(node);		// Init the queue with root element, thats where we will start our traversal from
	
	vector<int> v;		// To store the elements at each level, we can print them later
	
	
	while(!q.empty()) {
		
		int sz = q.size();		// We store the queue size for further iteration, if we directly use q.size() in for loop for end, it will give us wrong answer because queue size will be increasing as we will be adding elements of each level
		
		for(int i = 0; i<sz; i++) {
			Node* curr = q.front();		// Store front element of the queue in a temp element;
			q.pop();					// Removal because we will removing elements of this level in this for loop
			
			v.push_back(curr->data);
			
			if(curr->left) {
				q.push(curr->left);
			}
			if(curr->right) {
				q.push(curr->right);		// We have added the elements to the queue, but this will be reflected when this for loop ends, and it begins from 0 again, because this time number of iterations is the number of elements in this level.
			}
		}
	}
	return v;
}