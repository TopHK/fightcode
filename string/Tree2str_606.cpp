#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void tree2strCore(TreeNode* t, string &str)
    {
        if(t == NULL) return;
        str = str + to_string(t->val);
        if(t->left)
        {
            str += '(';
            tree2strCore(t->left, str);
            str += ')';
        }
        else if(t->right) str += "()";
        if(t->right)
        {
            str += '(';
            tree2strCore(t->right, str);
            str += ')';
        }
    }
    string tree2str(TreeNode* t)
    {
        string str;
        tree2strCore(t, str);
        return str;
    }
};

int main()
{
    Solution solution;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    cout<<solution.tree2str(node1)<<endl;
    return 0;
}


/*
You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.

The null node needs to be represented by empty parenthesis pair "()". And you need to omit all the empty parenthesis pairs that
don't affect the one-to-one mapping relationship between the string and the original binary tree.

Example 1:
Input: Binary tree: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

Output: "1(2(4))(3)"

Explanation: Originallay it needs to be "1(2(4)())(3()())",
but you need to omit all the unnecessary empty parenthesis pairs.
And it will be "1(2(4))(3)".
Example 2:
Input: Binary tree: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

Output: "1(2()(4))(3)"

Explanation: Almost the same as the first example,
except we can't omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
*/
