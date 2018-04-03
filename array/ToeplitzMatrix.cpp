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
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        if(rows <= 1) return true;
        int cols = matrix[0].size();
        if(cols <= 1) return true;
        for(int row = 1; row < rows; ++row)
        {
            for(int col = 1; col < cols; ++col)
            {
                int formerValue = matrix[row-1][col-1];
                int currentValue = matrix[row][col];
                if(currentValue != formerValue) return false;
            }
        }
        return true;
    }

};

int main()
{
    Solution solution;
//    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    vector<vector<int>> matrix = {{1,2},{2,2}};
    if(solution.isToeplitzMatrix(matrix)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

