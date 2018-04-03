#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int fromLeftRightTop(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        // from left to right
        for(int r = 0; r < rows; ++r)
        {
            for(int c = 0; c < cols; ++c)
            {
                if(grid[r][c] == 1)
                {
                    int leftPos = c - 1, upperPos = r - 1;
                    int leftValue = 0, upperValue = 0, diagonalValue = 0;
                    if(leftPos >= 0)  leftValue = grid[r][leftPos];
                    if(upperPos >= 0) upperValue = grid[upperPos][c];
                    if(leftPos >= 0 && upperPos >= 0) diagonalValue = grid[upperPos][leftPos];
                    if(diagonalValue == 0)
                    {
                        grid[r][c] += (leftValue + upperValue);
                    }
                    else 
                    {
                        grid[r][c] += max(leftValue,upperValue);
                        if(min(leftValue, upperValue) > 0) ++grid[r][c];
                    }
                    if(grid[r][c] > maxArea) maxArea = grid[r][c];
                }
            }
        }
        // reset grid
        for(int r = 0; r < rows; ++r)
        {
            for(int c = 0; c < cols; ++c)
            {
                if(grid[r][c] > 1)
                {
                    grid[r][c] = 1;
                }
            }
        }
        return maxArea;
    }
    int fromRightLeftTop(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        // from right to left 
        for(int r = 0; r < rows; ++r)
        {
            for(int c = cols-1; c >= 0; --c)
            {
                if(grid[r][c] == 1)
                {
                    int rightPos = c + 1, upperPos = r - 1;
                    int rightValue = 0, upperValue = 0, diagonalValue = 0;
                    if(rightPos < cols)  rightValue = grid[r][rightPos];
                    if(upperPos >= 0) upperValue = grid[upperPos][c];
                    if(rightPos < cols && upperPos >= 0) diagonalValue = grid[upperPos][rightPos];
                    if(diagonalValue == 0)
                    {
                        grid[r][c] += (rightValue + upperValue);
                    }
                    else 
                    {
                        grid[r][c] += max(rightValue,upperValue);
                        if(min(rightValue, upperValue) > 0) ++grid[r][c];
                    }
                    if(grid[r][c] > maxArea) maxArea = grid[r][c];
                }
            }
        }
        // reset grid
        for(int r = 0; r < rows; ++r)
        {
            for(int c = 0; c < cols; ++c)
            {
                if(grid[r][c] > 1)
                {
                    grid[r][c] = 1;
                }
            }
        }
        return maxArea;
    }
    int fromLeftRightBottom(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        // from left to right
        for(int r = rows-1; r >= 0; --r)
        {
            for(int c = 0; c < cols; ++c)
            {
                if(grid[r][c] == 1)
                {
                    int leftPos = c - 1, lowerPos = r + 1;
                    int leftValue = 0, lowerValue = 0, diagonalValue = 0;
                    if(leftPos >= 0)  leftValue = grid[r][leftPos];
                    if(lowerPos < rows) lowerValue = grid[lowerPos][c];
                    if(leftPos >= 0 && lowerPos < rows) diagonalValue = grid[lowerPos][leftPos];
                    if(diagonalValue == 0)
                    {
                        grid[r][c] += (leftValue + lowerValue);
                    }
                    else 
                    {
                        grid[r][c] += max(leftValue,lowerValue);
                        if(min(leftValue, lowerValue) > 0) ++grid[r][c];
                    }
                    if(grid[r][c] > maxArea) maxArea = grid[r][c];
                }
            }
        }
        // reset grid
        for(int r = 0; r < rows; ++r)
        {
            for(int c = 0; c < cols; ++c)
            {
                if(grid[r][c] > 1)
                {
                    grid[r][c] = 1;
                }
            }
        }
        return maxArea;
    }
    int fromRightLeftBottom(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        // from right to left 
        for(int r = rows-1; r >= 0; --r)
        {
            for(int c = cols-1; c >= 0; --c)
            {
                if(grid[r][c] == 1)
                {
                    int rightPos = c + 1, lowerPos = r + 1;
                    int rightValue = 0, lowerValue = 0, diagonalValue = 0;
                    if(rightPos < cols)  rightValue = grid[r][rightPos];
                    if(lowerPos < rows) lowerValue = grid[lowerPos][c];
                    if(rightPos < cols && lowerPos < rows) diagonalValue = grid[lowerPos][rightPos];
                    if(diagonalValue == 0)
                    {
                        grid[r][c] += (rightValue + lowerValue);
                    }
                    else 
                    {
                        grid[r][c] += max(rightValue,lowerValue);
                        if(min(rightValue, lowerValue) > 0) ++grid[r][c];
                    }
                    if(grid[r][c] > maxArea) maxArea = grid[r][c];
                }
            }
        }
        // reset grid
        for(int r = 0; r < rows; ++r)
        {
            for(int c = 0; c < cols; ++c)
            {
                if(grid[r][c] > 1)
                {
                    grid[r][c] = 1;
                }
            }
        }
        return maxArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int maxArea = 0;
        int leftRightTopMax = fromLeftRightTop(grid);
        if(leftRightTopMax > maxArea) maxArea = leftRightTopMax;
        int rightLeftTopMax = fromRightLeftTop(grid);
        if(rightLeftTopMax > maxArea) maxArea = rightLeftTopMax;
        int leftRightBottomMax = fromLeftRightBottom(grid);
        if(leftRightBottomMax > maxArea) maxArea = leftRightBottomMax;
        int rightLeftBottomMax = fromRightLeftTop(grid);
        if(rightLeftBottomMax > maxArea) maxArea = rightLeftBottomMax;
        return maxArea;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}    
    };
    cout<<solution.maxAreaOfIsland(grid)<<endl;
    return 0;
}

