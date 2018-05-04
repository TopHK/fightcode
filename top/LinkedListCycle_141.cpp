/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

bool hasCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* quick = head;
    while(quick && quick->next)
    {
        slow = slow->next;
        quick = quick->next->next;
        if(slow == quick) return true;
    }
    return false;
}
