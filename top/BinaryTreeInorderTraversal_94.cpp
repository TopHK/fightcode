/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> cache;
    vector<int> result;

    TreeNode* curNode = root;
    while(curNode || !cache.empty())
    {
        if(curNode)
        {
            cache.push(curNode);
            curNode = curNode->left;
        }
        else
        {
            TreeNode* temp = cache.top();
            cache.pop();
            result.push_back(temp->val);
            curNode = curNode->right;
        }
    }
    return result;
}
