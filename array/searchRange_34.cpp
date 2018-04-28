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
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int size = nums.size();
        int left = 0, right = size-1;
        vector<int> result(2, -1);
        while(left <= right)
        {
            int mid = left + ((right-left)>>1);
            if(nums[mid] == target)
            {
                if(mid == 0 || nums[mid-1] != target)
                {
                    result[0] = mid;
                    break;
                }
                right = mid-1;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        if(result[0] == -1) return result;

        left = result[0];
        right = size-1;
        while(left <= right)
        {
            int mid = left + ((right-left)>>1);
            if(nums[mid] == target)
            {
                if(mid == size-1 || nums[mid+1] != target)
                {
                    result[1] = mid;
                    break;
                }
                left = mid+1;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return result;
    }
};

void printVector(const vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Solution solution;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    printVector(solution.searchRange(nums, target));
    return 0;
}


/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
