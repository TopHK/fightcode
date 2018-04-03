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
    int triangleNumber(vector<int>& nums)
    {
        int size = nums.size();
        if(size < 3) return 0;

        int count = 0;
        sort(nums.begin(), nums.end());
        for(int k = size-1; k >= 2; k--)
        {
            int i = 0, j = k-1;
            while(i < j)
            {
                if(nums[i] + nums[j] > nums[k])
                {
                    count += (j - i);
                    j--;
                }
                else i++;
            }
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
    vector<int> nums = {2,2,3,4};
    cout<<solution.triangleNumber(nums)<<endl;
    return 0;
}


/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/
