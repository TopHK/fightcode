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
    bool containsDuplicate(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 1) return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size-1; ++i)
        {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
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

