/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

bool symmetricCore(TreeNode* tree1, TreeNode* tree2)
{
    if(!tree1 && !tree2) return true;
    if(!tree1 || !tree2) return false;
    if(tree1->val != tree2->val) return false;
    return symmetricCore(tree1->left, tree2->right) && symmetricCore(tree1->right, tree2->left);
}

bool isSymmetric(TreeNode* root)
{
    if(!root) return true;
    return symmetricCore(root->left, root->right);
}
