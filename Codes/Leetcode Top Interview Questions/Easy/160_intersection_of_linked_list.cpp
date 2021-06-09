ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA && !headB)
            return NULL;
        
        if(!headA)
            return headB;
        
        if(!headB)
            return headA;
        
        
        // Two lists intersect means there is 1 common node
        // Create a set to hold all the links, whichever one comes twice, is the intersection node
        
        set<ListNode*> s;
        while(headA)
        {
           s.insert(headA);
           headA = headA->next;
        }
        
        while(headB)
        {
            if(s.find(headB) == s.end())
            {
                headB = headB->next;
            }
            else
                return headB;
        }
        
        return NULL;
        
    }