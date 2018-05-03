/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

int getMajorityNum(vector<int>& nums)
{
    if(nums.empty()) return 0;
    int diffCount = 0;
    int majorityNum;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(diffCount == 0)
        {
            majorityNum = nums[i];
            diffCount = 1;
        }
        else if(nums[i] == majorityNum) ++diffCount;
        else --diffCount;
    }
    return majorityNum;
}

int main()
{
    vector<int> nums = {2,3,2};
    cout<<getMajorityNum(nums)<<endl;
    return 0;
}
