struct node *reverse (struct node *head, int k)
{ 
    // Solving base case
    
    if(!head) {
        return NULL;
    }
    
    if(head->next==NULL) {
        return head;
    }
    
    struct node* curr = head;
    struct node* prev = NULL, *next = NULL;
    int count = 0;
    
    // Reverse first k nodes
    while(curr !=NULL && count < k) {
        
        next = curr->next;          // Storing next pointer because after we reverse for current one, we need this
        curr->next = prev;          // Key point, making current node to point to previous instead of next
        
        prev = curr;                // Prev is moved 1 pointer ahead, coming to current pointer
        curr = next;                // curr is moved 1 pointer ahead, coming to next pointer
        
        count++;
    }
    
    // This is the part where we take care of the rest of the linked list where reverse operation has to be performed
    // Right now, next is pointing to k+1th element
    // 1->2->3->4->5->6->7->8, for k = 4, at the end of above while loop, next points to 5
    // So we make a recursive call, taking that element as head
    
    if(next != NULL) {
        // Note that head->next basically gets the value of prev, as denoted by the return statement of this function
        // This head->next was not my thinking, nor I could come up with such logic on my own at this stage. Taken from gfg 
        head->next = reverse(next, k);      // Note that we passed next as head.
    }
    
    // From the while loop above, we see prev takes the value of curr, making it head at the end.
    // This is in agreement with the fact that in standard linked list reversal questions we do head = prev and return head
    return prev;
    
}