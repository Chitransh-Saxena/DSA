 /*
    Logic is to make this node have the value of next node
    Sequence of changing value and next pointer matters
 */
 
 
 void deleteNode(ListNode* node) {
        
       if(!node)
            return;
        
        node -> val = node->next->val;
        node -> next = node->next->next;
    }