/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

ListNode* mergeList(ListNode* l1, ListNode* l2)
{
    ListNode dumpy(0);
    ListNode* curNode = &dumpy;
    while(l1 || l2)
    {
        if(!l1)
        {
            curNode->next = l2;
            l2 = l2->next;
        }
        else if(!l2)
        {
            curNode->next = l1;
            l1 = l1->next;
        }
        else if(l1->val <= l2->val)
        {
            curNode->next = l1;
            l1 = l1->next;
        }
        else
        {
            curNode->next = l2;
            l2 = l2->next;
        }
        curNode = curNode->next;
    }
    return dumpy.next;
}
