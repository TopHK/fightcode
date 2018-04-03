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
    int missingNumber_v1(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; ++i)
            nums[abs(nums[i])] = -1 * nums[abs(nums[i])];
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0) return i;
            if(i > 0 && nums[i] == 0) return i;
        }
    }
    int missingNumber(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] <= 0) continue;
            int currentNum = abs(nums[i]);
            int desPos = currentNum - 1;
            if(nums[desPos] == 0) nums[desPos] = -1 * currentNum; 
            else nums[desPos] = -1 * nums[desPos];
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] >= 0) return i+1;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
//    vector<int> nums = {3,0,1};
//    vector<int> nums = {2, 0};
    cout<<solution.missingNumber(nums)<<endl;
    return 0;
}

