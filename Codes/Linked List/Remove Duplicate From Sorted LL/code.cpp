Node *removeDuplicates(Node *root)
{
    
    if(root == NULL) {			// Base Corner Case
        return NULL;
    }
    Node* curr = root;
    // Node* prev = NULL, *next = NULL;
    
    while(curr && curr->next) {
        
        if(curr->data == curr->next->data) {		// Comparing current and next element
            curr->next = curr->next->next;			// Making current's next point to one element ahead than it usually does
        }
        else {
            curr = curr->next;
        }
    }
    return root;
 
}




