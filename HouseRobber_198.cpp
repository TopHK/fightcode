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
    int rob(vector<int>& nums)
    {

    }

};

int main()
{
    Solution solution;
//    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> nums = {1, 2, 3, 4, 5, 2};
    if(solution.containsDuplicate(nums)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
