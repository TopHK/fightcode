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
public:
    void combinationCore(vector<int>& candidates, vector<int> &possibleResult, int target, int currentIndex)
    {
        if(target == 0)
        {
//            if(find(result.begin(), result.end()) == result.end())
                result.push_back(possibleResult);
            return;
        }
        if(target < 0 || currentIndex >= candidates.size()) return;

//        combinationCore(candidates, possibleResult, target, currentIndex+1);
        if(target >= candidates[currentIndex])
        {
            possibleResult.push_back(candidates[currentIndex]);
            combinationCore(candidates, possibleResult, target-candidates[currentIndex], currentIndex+1);
            combinationCore(candidates, possibleResult, target-candidates[currentIndex], currentIndex);
            possibleResult.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> possibleResult;
        sort(candidates.begin(), candidates.end());
        combinationCore(candidates, possibleResult, target, 0);
        return result;
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
//    vector<vector<int> > matrix = {
//      {1,2,3},
//      {4,5,6},
//      {7,8,9}
//    };

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solution.combinationSum(candidates, target);
    printVector2D(result);
    return 0;
}


/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
*/
