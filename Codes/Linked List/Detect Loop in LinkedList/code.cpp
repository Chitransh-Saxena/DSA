bool detectLoop(Node* head)
{
    
    // your code here
    
    // First approach was to make a map of data, but data could be repeated, node cannot. So better appraoch to make a set of node
    // And check if that node ever appears in set.
    set<Node*> s;
    while(head) {
        
        if(s.find(head) != s.end()) {
            return true;
        }
        s.insert(head);
        head = head->next;
    }
    
    
    return false;
    
}