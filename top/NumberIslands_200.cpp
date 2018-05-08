void DFS(vector<vector<char>>& grid, int row, int col)
{
    if(row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0') return;
    grid[row][col] = '0';
    DFS(grid, row-1, col);
    DFS(grid, row+1, col);
    DFS(grid, row, col-1);
    DFS(grid, row, col+1);
}

int numIslands(vector<vector<char>>& grid)
{
    if(grid.empty()) return 0;

    int count = 0;
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            if(grid[i][j] == '1')
            {
                ++count;
                DFS(grid, i, j);
            }
        }
    }
}
