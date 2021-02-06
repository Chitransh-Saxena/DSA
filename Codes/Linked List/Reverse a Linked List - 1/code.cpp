

// Reversing a linked list

struct Node* reverseList(struct Node* head) {
	
	if(head->next == NULL) {			// Corner case of a linked list made of single element
        return head;
    }
    
    if(head == NULL) {					// Corner case of a linked list made of 0 elements
        return head;	
    }

	struct Node* temp = head;			// Creating a temp variable to move the pointer forward
	
	// In a linked list, we always know the address of the next link, not the previous link, so in order to reset the pointer to make it point to the previous node, we create variable to store the previous pointer
	// Created a next pointer to keep track of previous and next pointers in each iteration
	struct Node* prev = NULL, *next_ = NULL;		
	
	while(temp) {
	
		// Making head pointer's next to NULL instead of another pointer, making it end of linked list
		next_ = temp->next;
		temp->next = prev;
		
		prev = temp;
		temp = next_;
	}
	// In original linked list, last element would be pointing to a NULL pointer (which marks the end of linked list).
	// So, at the end of above iteration, prev has address of last pointer, temp and next are NULL.
	// So making prev as the new head of the linked list.
	head = prev;			
	
	return head;
}