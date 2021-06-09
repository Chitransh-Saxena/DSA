/*

    This question should not come in linked list because it literally combines 2 and more concepts in one

    So, basically there could be 2 main approaches
    1. Create a new linked list which is reverse of this linked list, and compare element by element (one from front, one from the back)
    2. We take half the linked list, revert it, and compare it with other half, if it has to be palindrome, elements have to be totally same
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* revertList(ListNode* node)
{
    ListNode* next_ = NULL;
    ListNode* prev = NULL;
    ListNode* curr = node;

    while(curr->next)
    {
        next_ = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next_;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
        
        if(!head)
            return false;
        

        // Reach the mid point of the linked list
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;

        while(fast_ptr && fast_ptr->next)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }

        // If there are odd number of objects, we are gonna ignore the middle objecrt
        if(fast_ptr)
        {
            slow_ptr = slow_ptr->next;
        }

        // Now slow_ptr is on the middle point, so we revert that
        slow_ptr = revertList(slow_ptr);

        // Before revert slow_ptr was pointing from mid till end, so now we have a head from end till mid of the list
        // We just have to compare the values now


        while(slow_ptr)
        {
            if(slow_ptr->val != head->val)
                return false;
            
            slow_ptr = slow_ptr->next;
            head = head->next;
        }

        return true;
        
        
    }