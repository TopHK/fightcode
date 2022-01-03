#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(NULL) {};
};

struct cmp{
    bool operator() (ListNode* p1, ListNode* p2) {
        return p1->val > p2->val;
    }
};

ListNode *MergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> queue;
    for (int i = 0; i < lists.size(); ++i) {
        if (lists[i]) {
            queue.push(lists[i]);
        }
    }
    ListNode dummy_node(-1);
    ListNode* p = &dummy_node;
    while (!queue.empty()) {
        ListNode* current_node = queue.top();
        queue.pop();
        p->next = current_node;
        p = p->next;
        if (current_node->next) {
            queue.push(current_node->next);
        }
    }
    return dummy_node.next;
}

ListNode* CreateList(const vector<int>& nums) {
    ListNode dummy_node(-1);
    ListNode* p = &dummy_node;
    for (const auto& num : nums) {
        ListNode* current_node = new ListNode(num);
        p->next = current_node;
        p = p->next;
    }
    return dummy_node.next;
}

void PrintList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    ListNode* head1 = CreateList(nums1);
    vector<int> nums2 = {2, 3, 4, 6};
    ListNode* head2 = CreateList(nums2);
    vector<int> nums3 = {3, 5, 7};
    ListNode* head3 = CreateList(nums3);
    vector<ListNode*> lists = {NULL, head1, head2, NULL, head3, NULL};
    ListNode* new_head = MergeKLists(lists);
    PrintList(new_head);
    return 0;
}