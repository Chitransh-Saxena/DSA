ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode* s = new ListNode(-1);
        ListNode* h = s;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                h->next = l1;
                h = h->next;
                l1 = l1->next;
            }
            else
            {
                h->next = l2;
                h = h->next;
                l2 = l2->next;
            }
        }
        
        if(l1)
        {
            h->next = l1;
        }
        if(l2)
        {
            h->next = l2;
        }
        
        return s->next;
    }