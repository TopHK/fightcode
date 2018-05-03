/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

TreeNode* convertBST(vector<int>& nums)
{
    int size = nums.size();
    TreeNode* root = convertBST(nums, 0, size-1);
    return root;
}

TreeNode* convertCore(vector<int>& nums, int left, int right)
{
    if(left > right) return NULL;
    int middle = left + ((right-left)>>1);
    TreeNode* root = new TreeNode(nums[middle]);
    root->left = convertCore(nums, left, middle-1);
    root->right = convertCore(nums, middle+1, right);
    return root;
}
