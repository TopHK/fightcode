#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {};
};

TreeNode* CreateTree(vector<int>::iterator xianxu_left, vector<int>::iterator xianxu_right,
                     vector<int>::iterator zhongxu_left, vector<int>::iterator zhongxu_right) {
    if (xianxu_left > xianxu_right) {
        return NULL;
    }
    TreeNode* root = new TreeNode(*xianxu_left);
    vector<int>::iterator root_pos = find(zhongxu_left, zhongxu_right + 1, *xianxu_left);
    int left_size = root_pos - zhongxu_left;
    int right_size = zhongxu_right - root_pos;
    if (left_size > 0) {
        root->left = CreateTree(xianxu_left + 1, xianxu_left + left_size, zhongxu_left, root_pos - 1);
    }
    if (right_size > 0) {
        root->right = CreateTree(xianxu_left + left_size + 1, xianxu_right, root_pos + 1, zhongxu_right);
    }
    return root;
}

vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
    if (xianxu.empty()) {
        return vector<int>{};
    }
    TreeNode *root = CreateTree(xianxu.begin(), xianxu.end()-1, zhongxu.begin(), zhongxu.end()-1);
    queue<TreeNode*> cache;
    cache.push(root);
    vector<int> result;
    while (!cache.empty()) {
        queue<TreeNode*> next_level_cache;
        while (!cache.empty()) {
            TreeNode* current_node = cache.front();
            cache.pop();
            if (current_node->left) {
                next_level_cache.push(current_node->left);
            }
            if (current_node->right) {
                next_level_cache.push(current_node->right);
            }
            if (cache.empty()) {
                result.push_back(current_node->val);
            }
        }
        cache.swap(next_level_cache);
    }
    return result;
}

int main() {
    vector<int> xianxu = {1,2,8,4,5,6,7,3};
    vector<int> zhongxu = {8,2,1,5,7,6,4,3};
    vector<int> result = solve(xianxu, zhongxu);
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout <<endl;
    return 0;
}