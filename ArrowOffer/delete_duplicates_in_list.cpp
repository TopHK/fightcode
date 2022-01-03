#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int value):val(value), next(NULL) {}
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

ListNode* DeleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode dummy_node(-1);
    dummy_node.next = head;
    ListNode* pre_node = &dummy_node;
    ListNode* cur_node = head;
    while(cur_node->next) {
        if (cur_node->val == cur_node->next->val) {
            int target = cur_node->val;
            cur_node = pre_node->next;
            while(cur_node && cur_node->val == target) {
                ListNode* to_delete = cur_node;
                cur_node = cur_node->next;
                delete to_delete;
            }
            pre_node->next = cur_node;
        } else {
            pre_node = cur_node;
            cur_node = cur_node->next;
        }
    }
    return dummy_node.next;
}

int main() {
//    vector<int> nums = {1, 2, 3, 3, 4, 4, 5};
    vector<int> nums = {1, 1, 1, 3, 3, 4, 4, 5};
    ListNode* head = CreatList(nums);
    PrintList(head);
    ListNode* new_head = DeleteDuplicates(head);
    PrintList(new_head);
    return 0;
}