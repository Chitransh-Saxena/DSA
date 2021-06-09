    /*
        Need 2 pointers to keep track of previous and make it next...

    */
    
    
    ListNode* reverseList(ListNode* head) {
        
        if(!head)
            return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next_ = NULL;
        
        while(curr)
        {
            next_ = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next_;
            
        }
        
        return prev;
    }