bool CheckBalancedTree(TreeNode* root, int &tree_depth) {
    if (!root) {
        tree_depth = 0;
        return true;
    }
    int left_depth = 0, right_depth = 0;
    if (!CheckBalancedTree(root->left, left_depth) || !CheckBalancedTree(root->right, right_depth)) {
        return false;
    }
    tree_depth = 1 + max(left_depth, right_depth);
    return abs(left_depth - right_depth) <= 1;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    int tree_depth = 0;
    return CheckBalancedTree(pRoot, tree_depth);
}