/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v):val(v), next(NULL){}
};

void deleteNode(ListNode *toBeDelete)
{
    ListNode* nextNode = toBeDelete->next;
    toBeDelete->val = nextNode->val;
    toBeDelete->next = nextNode->next;
    delete nextNode;
    nextNode = NULL;
}
