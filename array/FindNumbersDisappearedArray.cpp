#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

void printVector(const vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i) cout<<nums[i]<<" ";
    cout<<endl;
}

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
        {
            int temp = abs(nums[i]) - 1;
            if(nums[temp] < 0) continue;
            nums[temp] = -1 * nums[temp];
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0) result.push_back(i+1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    printVector(solution.findDisappearedNumbers(nums));
    return 0;
}

