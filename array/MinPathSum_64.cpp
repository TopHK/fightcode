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
    int minPathSum(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid[0].size();
        for(int i = 1; i < rows; ++i) grid[i][0] += grid[i-1][0];
        for(int j = 1; j < cols; ++j) grid[0][j] += grid[0][j-1];
        for(int i = 1; i < rows; ++i)
        {
            for(int j = 1; j < cols; ++j)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
        return grid[rows-1][cols-1];
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
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    cout<<solution.minPathSum(grid)<<endl;
    printVector2D(grid);
    return 0;
}


/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.
*/
