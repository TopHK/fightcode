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
    int majorityElement(vector<int>& nums)
    {
        int count = 1;
        int majorityNum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != majorityNum)
            {
                if(--count < 0)
                {
                    majorityNum = nums[i];
                    count = 1;
                }
            }
            else count++;
        }
        return majorityNum;
    }

};

int main()
{
    Solution solution;
    vector<int> nums = {2,2,3,5,7,2,8,2,2,2,2};
    cout<<solution.majorityElement(nums)<<endl;
    return 0;
}

