 /*
    Cycle means repeated one node
    We maintain a set of nodes, and check if any node has appeared twice, if yes, thats the cycle node
 */
 
 
 bool hasCycle(ListNode *head) {
        
        
        if(!head)
            return false;
        
        set<ListNode*> s;
        while(head) {
            
            if(s.find(head) == s.end()) {
                s.insert(head);
                head = head->next;
            }
            else
                return true;
        }
        return false;
    }