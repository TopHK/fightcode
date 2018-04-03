#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
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
    int arrayPairSum(vector<int>& nums)
    {
    //	int arrayLength = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2) sum += nums[i];
        return sum;
    }

};

int main()
{
    Solution solution;
    vector<int> nums = {1, 4, 2, 3};
    cout<<solution.arrayPairSum(nums)<<endl;
    return 0;
}

