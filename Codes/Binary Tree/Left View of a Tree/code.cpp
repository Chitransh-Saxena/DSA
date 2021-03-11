/*
This approach is based on level order traversal, my other approach had a flaw.
The idea behind this approach is, on each level we add elements, and then, we add the first element of that level in the vector.
Since we are adding in left to right manner in each level, we know that first element of that level is left most element.
*/



vector<int> leftView(Node *root)
{   
    vector<int> v;
    
    if(!root) {
        return v;
    }

    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i<sz; i++) {
            Node* curr = q.front();
            q.pop();
            
            // Here is how we make sure we only add the left part and not the right, otherwise each iteration has content of that level and it will add all elements of that level.
            if(i == 0) {
                v.push_back(curr->data);
            }
            
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
    }
    return v;
    
}