/*
    Create an arbitrary head to start joining elements
    Loop till there are elements in both of the lists
    add them to the head whichever is lower


    At the end check if any item is there in any list, just add that entire list.
    We can confidently add those elements because we know since the lists were sorted, those are larger elements

*/


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode* newHead = new ListNode(-1);       // Arbitrary head for now, after this we will start keeping value
        ListNode* curr = newHead;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
            
            
        }
        
        if(l1)
        {
            curr->next = l1;
        }
        if(l2)
        {
            curr->next = l2;
        }
        
        
        return newHead->next;
        
    }