/*
    In a binary tree, maximum depth is the number of nodes along the longest path

            1
           / \
          2   3
                \
                 4

    Here max depth is 3.

    Approach behind solution?
    -> recursively traverse each node for left and right node
    -> Keep track of the level via return value
*/

int maxDepth(TreeNode* root)
{
    if(!root)
        return 0;

    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right)

    // + 1 because that's how we actually add up values to the final return value, else we would having 0s
    return left_height + 1 ? left_height > right_height : right_height + 1;
}