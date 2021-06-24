#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    /*
        Approach:
            -> Noob approach would be to traverse once, get the length, traverse again and get the middle element

            -> Better approach is two use 2 pointers, one is moving at speed of one node per iteration, another is moving at 2 nodes per iteration
                -> So, if they are both moving together, when the fast pointer reaches the end, the small would be pointing to the middle

    */

    ListNode* middleNode(ListNode* head) {
        
       ListNode* s = head;
       ListNode* f = head;

        if(!s)
            return NULL;
        
        
        if(!s->next)
            return s;

       while(f && f->next)
       {
           s = s->next;
           f = f->next->next;
       }

       return s;
        
    }
};