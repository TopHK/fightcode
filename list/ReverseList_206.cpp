#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseList_v1(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* prevNode = NULL;
        ListNode* curNode = head;
        ListNode* nextNode = head->next;
        while(curNode)
        {
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
            if(nextNode) nextNode = nextNode->next;
        }
        return prevNode;
    }
};

void printList(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    Solution solution;
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    ListNode* newHead = solution.reverseList(head);
    printList(newHead);
    return 0;
}


/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/
