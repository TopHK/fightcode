#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): val(value), left(NULL), right(NULL) {};
};

TreeNode* CreateTree() {
    TreeNode* root = new TreeNode(5);
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(8);
    root->left = node1;
    root->right = node2;
    node2->right = node3;
    return root;
}

void PrintTreePreorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    PrintTreePreorder(root->left);
    PrintTreePreorder(root->right);
}

void PrintTreeInorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PrintTreeInorder(root->left);
    cout << root->val << " ";
    PrintTreeInorder(root->right);
}

void PrintTreePostorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PrintTreePostorder(root->left);
    PrintTreePostorder(root->right);
    cout << root->val << " ";
}

TreeNode* RebuildTree(vector<int>::const_iterator preorder_left, vector<int>::const_iterator preorder_right,
                      vector<int>::const_iterator inorder_left, vector<int>::const_iterator inorder_right) {
    if (preorder_right <= preorder_left || inorder_right <= inorder_left
        || (preorder_right - preorder_left != inorder_right - inorder_left)) {
//        cout << "Invalid input" << endl;
        return NULL;
    }
    const int& root_val = *preorder_left;
    vector<int>::const_iterator root_it = find(inorder_left, inorder_right, root_val);
    int left_length = root_it - inorder_left;
    vector<int>::const_iterator left_tree_preorder_left = preorder_left + 1;
    vector<int>::const_iterator left_tree_preorder_right = preorder_left + 1 + left_length;
    vector<int>::const_iterator left_tree_inorder_left = inorder_left;
    vector<int>::const_iterator left_tree_inorder_right = root_it;
    vector<int>::const_iterator right_tree_preorder_left = left_tree_preorder_right;
    vector<int>::const_iterator right_tree_preorder_right = preorder_right;
    vector<int>::const_iterator right_tree_inorder_left = root_it + 1;
    vector<int>::const_iterator right_tree_inorder_right = inorder_right;
    TreeNode* root = new TreeNode(root_val);
    root->left = RebuildTree(left_tree_preorder_left, left_tree_preorder_right, left_tree_inorder_left, left_tree_inorder_right);
    root->right = RebuildTree(right_tree_preorder_left, right_tree_preorder_right, right_tree_inorder_left, right_tree_inorder_right);
    return root;
}

TreeNode* RebuildTreeMain(const vector<int>& preorder_vec, const vector<int>& inorder_vec) {
    return RebuildTree(preorder_vec.begin(), preorder_vec.end(), inorder_vec.begin(), inorder_vec.end());
}

TreeNode* NextNodeInoderList(TreeNode* root, TreeNode* current_node) {
    if (current_node->right != NULL) {
        TreeNode* p = current_node->right;
        while(p->left) {
            p = p->left;
        }
        return p;
    } else if (current_node->parent->left == current_node) {
        return current_node->parent;
    } else {
        TreeNode* p = current_node->parent;
        while(p->parent) {
            if (p->parent->left == p) {
                return p;
            }
            p = p->parent;
        }
    }
    return NULL;
}

int main() {
    vector<int> preorder_vec = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> inorder_vec = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode* root = RebuildTreeMain(preorder_vec, inorder_vec);
    PrintTreePreorder(root);
    cout << endl;
    PrintTreeInorder(root);
    cout << endl;
    PrintTreePostorder(root);
    return 0;
}