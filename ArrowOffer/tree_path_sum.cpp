
void GetSum(TreeNode* root, string num, int& sum) {
    if (!root) {
        if (!num.empty()) {
            sum += stoi(num);
        }
        return;
    }
    num += to_string(root->val);
    GetSum(root->left, num, sum);
    GetSum(root->right, num, sum);
}

int sumNumbers(TreeNode* root) {
    string num;
    int sum = 0;
    GetSum(root, num, sum);
    return sum;
}