/*
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
*/

ListNode* reverseList(ListNode* head)
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

bool isPalindrome(ListNode* head)
{
    if(!head || !head->next) return true;
    ListNode* slow = head;
    ListNode* quick = head;
    while(quick && quick->next)
    {
        slow = slow->next;
        quick = quick->next->next;
    }
    ListNode* head2 = reverseList(slow);

    while(head != slow)
    {
        if(head->val != head2->val) return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
