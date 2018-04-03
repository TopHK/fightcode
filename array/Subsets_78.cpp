#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printVector2D(vector<vector<int>> &nums)
{
    cout<<"size:"<<nums.size()<<endl;
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = 0; j < nums[i].size(); ++j)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}

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
    // 非递归实现
    vector<vector<int>> subsets_v1(vector<int>& nums)
    {
        vector<vector<int>> result;
        result.push_back(vector<int>{});
        for (int i = 0; i < nums.size(); ++i) {
            int count = result.size();
            for (int j = 0; j < count; ++j) {
                vector<int> tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }
        return result;
    }

    // 递归实现
    void subsetsCore_v2(const vector<int> &nums, int start)
    {
        int size = nums.size();
        if(size == 0) return;
        if(start == size)
        {
            result.push_back(currentSet);
            return;
        }
        subsetsCore_v2(nums, start+1);
        currentSet.push_back(nums[start]);
        subsetsCore_v2(nums, start+1);
        currentSet.pop_back();
    }

    vector<vector<int>> subsets_v2(vector<int>& nums)
    {
        subsetsCore_v2(nums, 0);
        return result;
    }

    // 递归实现2
    void subsetsCore(const vector<int> &nums, vector<int> &currentSolution, vector<vector<int>> &solution, int start)
    {
        solution.push_back(currentSolution);
        for(int i = start; i < nums.size(); ++i)
        {
            currentSolution.push_back(nums[i]);
            subsetsCore(nums, currentSolution, solution, i+1);
            currentSolution.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> solution;
        vector<int> currentSolution;
        subsetsCore(nums, currentSolution, solution, 0);
        return solution;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {2,1,3};
    vector<vector<int>> result = solution.subsets(nums);
    printVector2D(result);
    return 0;
}


/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

