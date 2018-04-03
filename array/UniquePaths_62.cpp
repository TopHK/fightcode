#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;


int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
private:
    int count;
public:
    void pathCore(int m, int n, int r, int c)
    {
        if(r > m-1 || c > n-1) return;
        if(r == m-1 && c == n-1)
        {
            count++;
            return;
        }
        pathCore(m, n, r+1, c);
        pathCore(m, n, r, c+1);
    }
    int uniquePaths_v1(int m, int n)
    {
        count = 0;
        pathCore(m, n, 0, 0);
        return count;
    }

    int uniquePaths_v2(int m, int n)
    {
        if(m == 1 || n == 1) return 1;
        double count = 1.0;
        int N = m + n - 2;
        int K = m - 1;
        for(int i = 1; i <= K; ++i)
            count = count * (N - K + i) * i;
        return int(count);
    }

    int uniquePaths(int m, int n)
    {
        if(m == 1 || n == 1) return 1;
        vector<vector<int>> matrix(m, vector<int>(n, 1));
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};


int main()
{
    Solution solution;
    int m = 2, n = 2;
    cout<<solution.uniquePaths(m, n)<<endl;
    return 0;
}


/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/


