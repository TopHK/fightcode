void connect(TreeLinkNode *root)
{
    TreeNode* pre = root;
    TreeNode* cur = NULL;

    while(pre)
    {
        cur = pre;
        while(cur && cur->left)
        {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
