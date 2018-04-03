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
    bool checkPossibility(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 2) return true;

        for(int i = 0; i < size-2; ++i)
        {
            if(nums[i+2] < nums[i+1] && nums[i+1] < nums[i])
                return false;
        }
        return true;
    }

};

int main()
{
    Solution solution;
//    vector<int> nums = {5, 4, 3, 5};
    vector<int> nums = {4, 2, 1};
    if(solution.checkPossibility(nums)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

