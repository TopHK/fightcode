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
    vector<int> findDuplicates_v1(vector<int>& nums) 
    {
        vector<int> result;
        int numSize = nums.size();
        if(numSize < 2) return result;
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != i+1 && nums[i] != -1)
            {
                int temp = nums[i];
                if(nums[temp-1] == nums[i])
                {
                    result.push_back(temp);
                    break;
                }
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        return result;
    }
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> result;
        int numSize = nums.size();
        if(numSize < 2) return result;
        for(int i = 0; i < nums.size(); ++i)
        {
            int pos = abs(nums[i]) - 1;
            nums[pos] = -1 * nums[pos];
            if(nums[pos] > 0) result.push_back(abs(nums[i]));
        }
        return result;
    }
};

void printVector(const vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int main()
{
    Solution solution;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    printVector(solution.findDuplicates(nums));
    return 0;
}

