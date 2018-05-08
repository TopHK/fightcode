int partitionVec(vector<int>& nums, int left, int right)
{
    if(left >= right) return left;
    int pivot = nums[left];
    while(left < right)
    {
        while(left < right && nums[right] >= pivot) --right;
        if(left < right) nums[left++] = nums[right];
        while(left < right && nums[left] < pivot) ++left;
        if(left < right) nums[right--] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

int quickSort(vector<int>& nums, int left, int right, int k)
{
    int pos = partitionVec(nums, left, right);
    if(pos == nums.size()-k) return nums[pos];
    else if(pos < nums.size()-k) left = pos + 1;
    else right = pos - 1;
    return quickSort(nums, left, right, k);
}

int findKthLargest(vector<int>& nums, int k)
{
    return quickSort(nums, 0, nums.size()-1, k);
}
