#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

void moveZeros(vector<int>& nums)
{
    int i = 0;
    for(int j = 0; j < nums.size(); ++j)
    {
        if(nums[j] != 0) nums[i++] = nums[j];
    }
    while(i < nums.size()) nums[i++] = 0;

}

void printVector(const vector<int> & nums)
{
    for(const auto& num : nums) cout<<num<<" ";
    cout<<endl;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeros(nums);
    printVector(nums);
    return 0;
}
