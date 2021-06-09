 vector<int> ans;
    void inorderTraversalHelper(TreeNode* root)
    {
        if(!root)
            return;
        
        if(root->left)
            inorderTraversalHelper(root->left);
        ans.push_back(root->val);
        if(root->right)
            inorderTraversalHelper(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root)
            return {};
        
        inorderTraversalHelper(root);
        return ans;
        
    }