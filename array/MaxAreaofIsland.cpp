#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

static string x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();

class Solution
{
private:
    vector<vector<bool>> seen;
public:
    int areaDFS(vector<vector<int>>& grid, int row, int col)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if(row < 0 || row >= rows || col < 0 || col >= cols || seen[row][col] || grid[row][col] == 0)
            return 0;
        seen[row][col] = true;
        return (1 + areaDFS(grid, row-1, col) + areaDFS(grid, row+1, col) + 
                areaDFS(grid, row, col-1) + areaDFS(grid, row, col+1));

    }
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i = 0; i < rows; ++i) seen.push_back(vector<bool>(cols, false));
        int maxArea = 0;
        for(int r = 0; r < rows; ++r)
        {
            for(int c = 0; c < cols; ++c)
            {
                if(grid[r][c] == 1 && seen[r][c] == false)
                {
                    maxArea = max(maxArea, areaDFS(grid, r, c));
                }
            }
        }
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

