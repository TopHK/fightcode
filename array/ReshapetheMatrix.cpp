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
    vector<vector<int>> matrixReshape_v1(vector<vector<int>>& nums, int r, int c)
    {
        int rows = nums.size();
        if(rows <= 0) return nums;
        int cols = nums[0].size();
        if(r*c != rows*cols) return nums;
        vector<vector<int>> result;
        int id = 0;
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                if((id % c) == 0) result.push_back(vector<int>());
                result[result.size()-1].push_back(nums[row][col]);
                ++id;
            }
        }
        return result;
    }
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        int rows = nums.size();
        if(rows <= 0) return nums;
        int cols = nums[0].size();
        if(r*c != rows*cols) return nums;
        vector<vector<int>> result(r, vector<int>(c, 0));
        int id = 0;
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                result[id/c][id%c] = nums[row][col];
                ++id;
            }
        }
        return result;
    }
};

void printVector2D(const vector<vector<int>>& nums)
{
    int rows = nums.size();
    int cols = nums[0].size();
    for(int r = 0; r < rows; ++r)
    {
        cout<<"row:"<<r+1<<endl;
        for(int c = 0; c < cols; ++c)
        {
            cout<<nums[r][c]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Solution solution;
    vector<vector<int>> nums = {{1,2},{2,2}};
    printVector2D(nums);
    int r = 1, c = 4;
    vector<vector<int>> result = solution.matrixReshape(nums, r, c);
    printVector2D(result);
    return 0;
}

