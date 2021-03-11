/*
The approach is similar to left view of the tree problem.
We do a level order traversal and add the right most element of tha level in vector of results
*/

vector<int> rightView(Node *root)
{
   // Your Code here
   vector<int> v;
        if(!root) {
            return v;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())  {
            int sz = q.size();      // Size of the level.
            for(int i = 1; i<=sz; i++) {    // i = 1 because easier to meet the right view condition
                Node* curr = q.front();
                q.pop();
                
                if(i == sz) {               // Right most element of the level
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