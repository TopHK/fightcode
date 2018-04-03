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
    int numSubarrayBoundedMax(vector<int>& A, int L, int R)
    {
        int maxCount = 0;
        int leftPos = -1;
        int rightPos = -1;
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i] > R) leftPos = i;
            if(A[i] >= L) rightPos = i;
            maxCount += (rightPos - leftPos);
        }
        return maxCount;
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
    vector<int> nums = {2, 1, 4, 3};
    int L = 2, R = 3;
    cout<<solution.numSubarrayBoundedMax(nums, L, R)<<endl;
    return 0;
}


/*

We are given an array A of positive integers, and two positive integers L and R (L <= R).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example :
Input:
A = [2, 1, 4, 3]
L = 2
R = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

L, R  and A[i] will be an integer in the range [0, 10^9].
The length of A will be in the range of [1, 50000].

C[i]与C[i-1]之间的关系是什么？
{2
*/
