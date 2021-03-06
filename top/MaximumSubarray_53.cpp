/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

int getMaxSubArr(vector<int>& nums)
{
    int maxSum = INT_MIN;
    int curSum = 0;
    for(const auto& num : nums)
    {
        if(curSum <= 0)
        {
            curSum = num;
        }
        else curSum += num;
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}
