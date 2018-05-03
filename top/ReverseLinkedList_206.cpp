/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

ListNode* reverseList_v1(ListNode* head)
{
    ListNode* prevNode = NULL;
    ListNode* curNode = head;
    while(curNode)
    {
        ListNode* nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
    }
    return prevNode;
}

ListNode* reverseList(ListNode* head)
{
    if(!head || !head->next) return head;
    ListNode* nextNode = head->next;
    ListNode* newHead = reverseList(nextNode);
    nextNode->next = head;
    head->next = NULL;
    return newHead;
}
