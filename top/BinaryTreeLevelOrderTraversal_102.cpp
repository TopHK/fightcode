vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    queue<TreeNode*> cache;
    if(!root) return result;
    cache.push(root);

    while(!cache.empty())
    {
        int size = cache.size();
        vector<int> tempVec;
        for(int i = 0; i < size; ++i)
        {
            TreeNode* tempNode = cache.front();
            cache.pop();
            tempVec.push_back(tempNode->val);
            if(tempNode->left) cache.push(tempNode->left);
            if(tempNode->right) cache.push(tempNode->right);
        }
        result.push_back(tempVec);
    }
    return result;
}

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> result;
    queue<TreeNode*> cache;
    if(!root) return result;
    cache.push(root);

    while(!cache.empty())
    {
        int size = cache.size();
        long long int sum = 1;
        int count = 0;
        for(int i = 0; i < size; ++i)
        {
            TreeNode* tempNode = cache.front();
            cache.pop();
            ++count;
            sum += tempNode->val;
            if(tempNode->left) cache.push(tempNode->left);
            if(tempNode->right) cache.push(tempNode->right);
        }
        result.push_back(sum / float(count));
    }
    return result;
}
