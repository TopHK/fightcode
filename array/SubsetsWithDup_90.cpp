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
private:
    vector<vector<int>> result;
    vector<int> currentSet;
public:
    vector<vector<int>> subsetsWithDup_v1(vector<int>& nums)
    {
        vector<vector<int>> result;
        result.push_back(vector<int>{});

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();)
        {
            int repeatCount = 0;
            while(i+repeatCount < nums.size() && nums[i] == nums[i+repeatCount])
                repeatCount++;

            int preCount = result.size();
            for(int j = 0; j < preCount; ++j)
            {
                vector<int> temp = result[j];
                for(int k = 0; k < repeatCount; ++k)
                {
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
            i += repeatCount;
        }
        return result;
    }

    // µÝ¹éÊµÏÖ
    void subsetsCore(const vector<int> &nums, vector<int> &currentSolution, vector<vector<int>> &solution, int start)
    {
        solution.push_back(currentSolution);
        for(int i = start; i < nums.size(); ++i)
        {
            if(i != start && nums[i] == nums[i-1]) continue;
            currentSolution.push_back(nums[i]);
            subsetsCore(nums, currentSolution, solution, i+1);
            currentSolution.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> solution;
        vector<int> currentSolution;
        sort(nums.begin(), nums.end());
        subsetsCore(nums, currentSolution, solution, 0);
        return solution;
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
    vector<int> nums = {1,2,2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);
    printVector2D(result);
    return 0;
}


/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
