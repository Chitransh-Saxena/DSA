/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        vector<ListNode*> v;
        
        while(head) {
            
            if(find(v.begin(), v.end(), head) != v.end()) {
                
                return head;
            }
            v.push_back(head);
            head = head->next;
        }
        return NULL;
    }
};