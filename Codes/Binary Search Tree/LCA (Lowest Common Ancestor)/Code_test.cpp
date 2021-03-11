/*
    For a given tree, find which node is last known parent/grandparent of the given 2 nodes

    Approach - Top Down approach
        -> If we are aware of the path taken by the two elements
        -> Then we can compare that what was the last element common between those two
        -> That element will be our LCA
        -> So we need to create a utility function to add elements of that path in a vector
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

Node* LCA(Node * root , int l , int h);

int main()
{

    int t = 1;
    while(t--)
    {
        string s = "5 4 6 3 N N 7 N N N 8";
        int l = 7, h = 8;
        Node* root = buildTree(s);
        cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}// } Driver Code Ends


/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root'

vector<Node*> getNodeToRootPath(Node* root, int x) {
    
    // We are adding from node to root (upward fashion), but we are provided with root
    // Fill up a vector with nodes from the point where x is found till root
    if(root->data == x) {
        vector<Node*> v;
        v.push_back(root);
        return v;
    }
    
    while(root->left || root->right) {
        
        
        // We are doing return in both cases because
        // Assume we found data in the root->left, then it is obvious we are not going to find that data in right subtree
        if(root->left) {
            
            // Expecting this path will have data
            vector<Node*> path_till_curr = getNodeToRootPath(root->left, x);
            
            // Checking if our assumption is correct or not
            if(path_till_curr.size() > 0) {
                path_till_curr.push_back(root);
                return path_till_curr;
            }
        }
        
        if(root->right) {
            
            vector<Node*> path_till_curr = getNodeToRootPath(root->right, x);
            if(path_till_curr.size() > 0) {
                path_till_curr.push_back(root);
                return path_till_curr;
            }
        }

        // In case both of them are null, it will be stuck in an infinite loop, so break it via this
        break;
    }
    vector<Node*> v;
    v.clear();
    return v;
}



Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   
   if(!root) {
       return NULL;
   }
   vector<Node*> v1 = getNodeToRootPath(root, n1);
   vector<Node*> v2 = getNodeToRootPath(root, n2);
   
   int i = v1.size() -1;
   int j = v2.size() -1;
   
  while(i>=0 && j >=0 && (v1[i]->data == v2[j]->data)) {
      // cout << "Comparing " << v1[i]->data << " and " << v2[j]->data << "\n";
      
      i--, j--;
  }
    i++, j++;
    return v1[i];
  
}

