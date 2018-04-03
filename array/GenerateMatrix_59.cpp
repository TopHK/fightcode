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
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int> > result(n, vector<int>(n, 0));
        if(n < 1) return result;

        int currentNum = 1;
        int halfLen = ((n & 1) ? (n+1)/2 : n/2);
        for(int i = 0; i < halfLen; ++i)
        {
            int circleLen = n - i*2;
            for(int c = i; c <= i+circleLen-1; ++c) result[i][c] = currentNum++;
            for(int r = i+1; r <= i+circleLen-1; ++r) result[r][i+circleLen-1] = currentNum++;
            for(int c = i+circleLen-2; c >= i; --c) result[i+circleLen-1][c] = currentNum++;
            for(int r = i+circleLen-2; r >= i+1; --r) result[r][i] = currentNum++;
        }
        return result;
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
    vector<vector<int>> result = solution.generateMatrix(n);
    printVector2D(result);
    return 0;
}


/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
