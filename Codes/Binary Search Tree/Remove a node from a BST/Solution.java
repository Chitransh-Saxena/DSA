/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    /*
        For any subtree, the maximum number is basically the right most element down the line
    */
    int max_node(TreeNode root){
        
        if(root.right != null){
            return max_node(root.right);
        }
        else{
            return root.val;
        }
    }
    
    public TreeNode deleteNode(TreeNode root, int key) {
        
        if(root == null){
            return null;
        }
        
        // Now recrusively we will find the element to be deleted (traversal of left and right subtree)
        // Once the element is found, we will delete it
        
        
        if(key < root.val){
            root.left = deleteNode(root.left, key);
        }
        else if (key > root.val){
            root.right = deleteNode(root.right, key);
        }
        
        // We found the key to be deleted
        else{
            
            // here there could be Multiple possiblities
            // Possibility 1. Element is a root node with no left or right subtree, this case is easy, mark this node as null and return
            
            if(root.right == null && root.left == null){
                return null;
            }
            
            // Possibility 2. The root has both left and right child
            /*
                -> In this case, the logic is as follows
                -> We know deleting a leaf node is easy, just return null for that case
                -> So, what we will do, we will find the most suitable leaf node which can take place of current node
                    -> Once that leaf node is found, we will overwrite the value of current node with that leaf node
                    -> Then we will go and delete that leaf node
                -> Now, the logic of how do we find the most appropriate leaf node?
                    -> At any level of a BST, the left child has to be smaller, and right has to be greater
                    -> So, any element taken from the right subtree would be greater than current node and left node, it satisfies the property of BST
                        -> But, we are looking for a leaf node, so let's assume we have a left leaf node and a right leaf node
                        -> If we choose the left one, it would be smaller than some of the nodes and greater than some nodes (diagram clarifies this), and thus not a good choice
                        -> If we choose the right leaf, it is logically wrong, because right leaf of a right subtree is the largest element, does not satisfy BST
                    
                    -> If check elements from the left subtee
                        -> If we pick left most leaf node, it would be smallest element, does not satisfy BST
                        -> If we pick the right most leaf node, it will be largest among the left subtree, so it can take the position
                        
                
                -> So, finally, we just find the right most leaf of the left subtree, use its value as root value, and go and delete that in that subtree
            */
            
            else if( root.left != null && root.right != null){
                
                int left_max = max_node(root.left);
                
                root.val = left_max;
                root.left = deleteNode(root.left, root.val);
                
                return root;
            }
            
            // Possibility 3: The node which we want to delete does not have right child, it has only left child
            // Then we just use the left chld instead of this current node which is parent
            // So, now this left child will connect to the grandparent node instead of parent node
            else if(root.left != null){
                return root.left;
            }
            
            else{
                return root.right;
            }
            
        }
        
        return root;
    }
}