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
    int findLength_v1(vector<int>& A, vector<int>& B)
    {
        int sizeA = A.size();
        int sizeB = B.size();
        int maxLength = 0;
        vector<vector<int>> dp(sizeA, vector<int>(sizeB, 0));

        for(int i = sizeA-1; i >= 0; i--)
        {
            for(int j = sizeB-1; j >= 0; j--)
            {
                if(A[i] == B[j])
                {
                    dp[i][j] = 1;
                    if(i+1 < sizeA && j+1 < sizeB)
                        dp[i][j] += dp[i+1][j+1];
                }
                maxLength = max(maxLength, dp[i][j]);
            }
        }
        return maxLength;
    }

    int findLength_v2(vector<int>& A, vector<int>& B)
    {
        int sizeA = A.size();
        int sizeB = B.size();
        int maxLength = 0;
        vector<vector<int>> dp(2, vector<int>(sizeB+1, 0));
        int currentRow = 0, nextRow = 1;

        for(int i = sizeA-1; i >= 0; i--)
        {
            for(int j = sizeB-1; j >= 0; j--)
            {
                if(A[i] == B[j]) dp[currentRow][j] = dp[nextRow][j+1] + 1;
                else dp[currentRow][j] = 0;
                maxLength = max(maxLength, dp[currentRow][j]);
            }
            currentRow = 1 - currentRow;
            nextRow = 1 - nextRow;
        }
        return maxLength;
    }

    int helper(vector<int>& A, vector<int>& B, int i, int j)
    {
        int len = 0, cnt = 0;
        for (;i < A.size() && j < B.size(); i++, j++)
        {
            if (A[i] == B[j])
                len = max(len, ++cnt);
            else
                cnt = 0;
        }
        return len;
    }
    int findLength(vector<int>& A, vector<int>& B)
    {
        int ans = 0, m = A.size(), n = B.size();
        for (int i = 0; i < m-ans; i++)
            ans = max(ans, helper(A, B, i, 0));
        for (int j = 0; j < n-ans; j++)
            ans = max(ans, helper(A, B, 0, j));
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> A = {1,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    cout<<solution.findLength(A, B)<<endl;
    return 0;
}


/*
    Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

    Example 1:
    Input:
    A: [1,2,3,2,1]
    B: [3,2,1,4,7]
    Output: 3
    Explanation:
    The repeated subarray with maximum length is [3, 2, 1].
    Note:
    1 <= len(A), len(B) <= 1000
    0 <= A[i], B[i] < 100
*/
