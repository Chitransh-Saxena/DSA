class Solution{
    public:
    int height(struct Node* node){
        
        // Question is pretty much same as level order traversal, we just have to count the number of levels.
        int h = 0;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            int sz = q.size();
            h+=1;
            
            for(int i = 0; i<sz; i++) {
                
                Node* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
        }
        return h;
    }
};


// Another Solution

int maxDepth(TreeNode* root) {
        
        if(!root) {
            return 0;
        }
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1 + max(lh, rh); 
    }