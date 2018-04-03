#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int size = nums.size();
        int start = 0, end = size-1;
        while(start < end-1)
        {
            int mid = start + ((end - start) >> 1);
            if(nums[mid] > nums[end])
                start = mid;
            else if(nums[mid] < nums[end])
                end = mid;
            else
            {
                int minNum = nums[0];
                for(int i = 1; i < size; ++i) minNum = min(minNum, nums[i]);
                return minNum;
            }
        }
        return min(nums[start], nums[end]);
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
    int n = 5;
    vector<int> case1 = {4,5,6,7,0,1,2};
    vector<int> case2 = {2,2,2,2,1,1,2};
    cout<<solution.findMin(case1)<<endl;
    cout<<solution.findMin(case2)<<endl;
    return 0;
}


/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
