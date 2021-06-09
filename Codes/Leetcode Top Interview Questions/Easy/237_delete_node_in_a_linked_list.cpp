/*
    We are given the node that we have to delete
    We just give this node the contents of the next node

    Now, the value is of next node
    And the next pointer contains the address of next to next pointer, thus we skip over 1 node, we are technically not deleting any node here
*/


void deleteNode(TreeNode* node)
{
    if(!node)
        return;

    node->val = node->next->val;
    node->next = node->next->next;
}