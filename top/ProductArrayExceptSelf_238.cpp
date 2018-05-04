/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int size = nums.size();
    vector<int> output(size, 1);
    for(int i = 1; i < size; ++i)
    {
        output[i] = output[i-1] * nums[i-1];
    }
    int rightProduct = 1;
    for(int i = size-2; i >= 0; --i)
    {
        rightProduct *= nums[i+1];
        output[i] = output[i] * rightProduct;
    }
    return output;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    for(const auto& num : result) cout<<num<<" ";
    cout<<endl;
    return 0;
}
