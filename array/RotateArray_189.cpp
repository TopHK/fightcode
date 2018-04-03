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
    void rotate_v1(vector<int>& nums, int k)
    {
        int size = nums.size();
        if(size <= 1) return;
        k %= size;
        for(int i = 0; i < k; ++i)
        {
            int temp = nums[size-1];
            for(int j = size-2; j >= 0; --j)
            {
                nums[j+1] = nums[j];
            }
            nums[0] = temp;
        }
    }
    void rotate(vector<int>& nums, int k)
    {
        int size = nums.size();
        if(size <= 1) return;
        k %= size;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

void printVector(vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

//int main()
//{
//    Solution solution;
//    vector<int> nums = {1,2,3,4,5,6,7};
//    int k = 8;
//    solution.rotate(nums, k);
//    printVector(nums);
//    return 0;
//}


/*
https://leetcode.com/problems/rotate-array/description/
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/
