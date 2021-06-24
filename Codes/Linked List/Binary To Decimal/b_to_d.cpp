#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

/*
    Logic 1:
        (My approach)
        -> Traverse from right to left and do this
        -> (2^(0) * num[0]) + (2^1 * num[1]) + (2^2 * num[2]) ...
        -> BUT, we cannot traverse from the right, since we are given the head of the left

    Logic 2:
        (Leetcode approach)
        -> Traverse from left to right and do this
        -> sum = head->val
        -> Now, we multiply this sum by 2, add it to the next value to get sum till now
            -> sum = (sum * 2) + head->next-val;
            -> Increment the head to move forth one position
                -> head = head->next;

*/




int getDecimalValue(ListNode* head)
{
    // 0101
    if(!head)
        return 0;
    
    int ans = head->val;
    while(head->next)
    {
        ans = (ans*2) + head->next->val;
        head = head->next;
    }

    return ans;
}