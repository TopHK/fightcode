#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printVector(vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    vector<int> productExceptSelf_v1(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> result1(size, 1);
        vector<int> result2(size, 1);
        vector<int> result(size, 1);

        for(int i = 1; i < size; ++i) result1[i] = result1[i-1] * nums[i-1];
        for(int j = size-2; j >= 0; --j) result2[j] = result2[j+1] * nums[j+1];
        for(int k = 0; k < size; ++k) result[k] = result1[k] * result2[k];
        return result;
    }
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> result(size, 1);

        for(int i = 1; i < size; ++i) result[i] = result[i-1] * nums[i-1];
        int tempNum = 1;
        for(int j = size-2; j >= 0; --j)
        {
            tempNum *= nums[j+1];
            result[j] *= tempNum;
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);
    printVector(result);
    return 0;
}


/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)


*/

