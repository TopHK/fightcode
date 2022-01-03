#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL) {};
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

ListNode* DeleteNode(ListNode* head, const int& target) {
    ListNode dummy_node(-1);
    dummy_node.next = head;
    ListNode* p = &dummy_node;
    while(p->next) {
        if (p->next->val == target) {
            ListNode* temp = p->next;
            p->next = p->next->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
    return dummy_node.next;
}

ListNode* AddToTail(ListNode* head, const int& value) {
    ListNode* new_node = new ListNode(value);
    ListNode dummy_node(-1);
    dummy_node.next = head;
    ListNode* p = &dummy_node;
    while(p->next) {
        p = p->next;
    }
    p->next = new_node;
    return dummy_node.next;
}

void PrintList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void PrintListReverse(ListNode* head) {
    stack<int> st;
    ListNode* p = head;
    while(p) {
        st.push(p->val);
        p = p->next;
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout <<endl;
}

void PrintListReverseV2(ListNode* head) {
    if (head == NULL) {
        return;
    }
    PrintListReverseV2(head->next);
    cout << head->val << " ";
}

int main() {
    vector<int> nums = {3, 5, 10, 6, 9, 7};
    ListNode* head = CreatList(nums);
    PrintList(head);
//    ListNode* new_head = DeleteNode(head, 8);
//    PrintList(new_head);
//    ListNode* new_head = AddToTail(head, 3);
//    PrintList(new_head);
//    PrintListReverse(head);
    PrintListReverseV2(head);
    return 0;
}