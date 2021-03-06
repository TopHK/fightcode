/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J
B:     b1 �� b2 �� b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/

ListNode* itersection(ListNode* headA, ListNode* headB)
{
    int lenA = 0;
    ListNode* curNode = headA;
    while(curNode)
    {
        ++lenA;
        curNode = curNode->next;
    }

    int lenB = 0;
    curNode = headB;
    while(curNode)
    {
        ++lenB;
        curNode = curNode->next;
    }

    if(lenA < lenB)
    {
        ListNode* temp = headA;
        headA = headB;
        headB = temp;
    }
    for(int i = 0; i < abs(lenA-lenB); ++i)
    {
        headA = headA->next;
    }
    while(headA && headB)
    {
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
