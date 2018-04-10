#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v): left(NULL), right(NULL), val(v){}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> nodes;
        stack<TreeNode*> toVisit;
        TreeNode* curNode = root;
        while (curNode || !toVisit.empty())
        {
            if (curNode)
            {
                toVisit.push(curNode);
                curNode = curNode -> left;
            }
            else
            {
                curNode = toVisit.top();
                toVisit.pop();
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        return nodes;
    }

};

void inorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)          // 1.
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            // find predecessor
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)   // 2.a)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else                       // 2.b)
            {
                prev->right = NULL;
                printf("%d ", cur->val);
                cur = cur->right;
            }
        }
    }
}

int main()
{
    Solution solution;
//    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> nums = {1, 2, 3, 4, 5, 2};
    if(solution.containsDuplicate(nums)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/
