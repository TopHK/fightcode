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
    vector<vector<int>> imageSmoother(vector<vector<int>>& M)
    {
        int rows = M.size();
        int cols = M[0].size();
        vector<vector<int>> result(rows,vector<int>(cols, 0));
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                int count = 1;
                int sum = M[i][j];

                if(i - 1 >= 0)
                {
                    sum += M[i-1][j];
                    ++count;
                    if(j - 1 >= 0)
                    {
                        sum += M[i-1][j-1];
                        ++count;
                    }
                    if(j + 1 < cols)
                    {
                        sum += M[i-1][j+1];
                        ++count;
                    }
                }
                if(i + 1 < rows)
                {
                    sum += M[i+1][j];
                    ++count;
                    if(j - 1 >= 0)
                    {
                        sum += M[i+1][j-1];
                        ++count;
                    }
                    if(j + 1 < cols)
                    {
                        sum += M[i+1][j+1];
                        ++count;
                    }
                }
                if(j - 1 >= 0)
                {
                    sum += M[i][j-1];
                    ++count;
                }
                if(j + 1 < cols)
                {
                    sum += M[i][j+1];
                    ++count;
                }
                result[i][j] = sum / count;
            }
        }
    return result;
    }
};

void printVector2D(const vector<vector<int>> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = 0; j < nums[0].size(); ++j)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    Solution solution;
    vector<vector<int>> M = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    vector<vector<int>> result = solution.imageSmoother(M);
    printVector2D(result);
    return 0;
}

