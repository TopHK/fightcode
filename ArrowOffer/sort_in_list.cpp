#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL){};
};

ListNode* CreatList(const vector<int>& nums) {
    ListNode dummy_node(-1);
    ListNode *p = &dummy_node;
    for (const auto& num: nums) {
        ListNode* new_node = new ListNode(num);
        p->next = new_node;
        p = p->next;
    }
    return dummy_node.next;
}

void PrintList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* MergeList(ListNode* head1, ListNode* head2) {
    if (!head1) {
        return head2;
    } else if (!head2) {
        return head1;
    }
    ListNode* new_head = NULL;
    if (head1->val < head2->val) {
        new_head = head1;
        head1 = head1->next;
    } else {
        new_head = head2;
        head2 = head2->next;
    }
    new_head->next = MergeList(head1, head2);
    return new_head;
}

ListNode* sortInList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode dummy_node(-1);
    ListNode* dummy_head = &dummy_node;
    dummy_head->next = head;
    ListNode *p = dummy_head, *q = dummy_head;
    while (q && q->next) {
        q = q->next->next;
        p = p->next;
    }
    ListNode* head2 = p->next;
    p->next = NULL;
    ListNode* new_head1 = sortInList(head);
    PrintList(new_head1);
    ListNode* new_head2 = sortInList(head2);
    PrintList(new_head2);
    return MergeList(new_head1, new_head2);
}

int main() {
    vector<int> nums = {3, 5, 10, 6, 9, 7};
    ListNode* head = CreatList(nums);
    ListNode* new_head = sortInList(head);
    PrintList(new_head);
}
