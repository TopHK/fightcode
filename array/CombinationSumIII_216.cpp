#include<iostream>
#include<vector>
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
    void combinationCore(int sum, int searchEnd, vector<int> &possibleResult, const int &k)
    {
        int size = possibleResult.size();
        if(size == k)
        {
            if(sum == 0) result.push_back(possibleResult);
            return;
        }
        else if(searchEnd > 9 || sum <= 0) return;

        // 不添加searchEnd这个元素
        combinationCore(sum, searchEnd+1, possibleResult, k);
        // 添加searchEnd这个元素
        possibleResult.push_back(searchEnd);
        combinationCore(sum-searchEnd, searchEnd+1, possibleResult, k);
        possibleResult.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> possibleResult;
        combinationCore(n, 1, possibleResult, k);
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
    int k = 3, n = 7;
    vector<vector<int>> result = solution.combinationSum3(k, n);
    printVector2D(result);
    return 0;
}


/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
