#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int subarraySum_v1(vector<int>& nums, int k)
    {
        int size = nums.size();
        int count = 0;
        for(int i = 0; i < size; ++i)
        {
            int sum = 0;
            for(int j = i; j < size; ++j)
            {
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }

    int subarraySum(vector<int>& nums, int k)
    {
        int size = nums.size();
        int count = 0;

        long long int sum = 0;
        unordered_map<long long, int> preSum;
        preSum[0] = 1;
        for(int i = 0; i < size; ++i)
        {
            sum += nums[i];
            if(preSum.count(sum - k) != 0) count += preSum[sum - k];
            preSum[sum]++;
        }
        return count;
    }
};

void printVector2D(vector<vector<int>> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = 0; j < nums[i].size(); ++j)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 1, 1, 1, -1, 4};
    int k = 3;
    cout<<solution.subarraySum(nums, k)<<endl;
    return 0;
}


/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/
