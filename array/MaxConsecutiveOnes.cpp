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
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int maxCount = 0;
        int currentCount = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i]) ++currentCount;
            else 
            {
                if(currentCount > maxCount) maxCount = currentCount;
                currentCount = 0;
            }
        }
        if(currentCount > maxCount) maxCount = currentCount;
        return maxCount;
    }

};

int main()
{
    Solution solution;
    vector<int> nums = {1,1,0,1,1,1};
    cout<<solution.findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}

