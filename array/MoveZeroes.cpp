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
    void moveZeroes_v1(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 1) return;
        int zeroPos = 0;
        int numPos = 1;
        while(zeroPos < size && numPos < size)
        {
            if(nums[zeroPos] != 0)
            {
                zeroPos++;
                continue;
            }
            numPos = zeroPos + 1;
            while(numPos < size)
            {
                if(nums[numPos] != 0) break;
                numPos++;
            }
            if(numPos >= size) break;
            nums[zeroPos] = nums[numPos];
            nums[numPos] = 0;
            zeroPos++;
            numPos = zeroPos+1;
        }
    }
    void moveZeroes(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 1) return;
        int zeroCount = 0;
        for(int i = 0; i < size; ++i)
        {
            if(nums[i] == 0) ++zeroCount;
            else nums[i-zeroCount] = nums[i];
        }
        for(int j = size-zeroCount; j < size; ++j) nums[j] = 0;
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
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    printVector(nums);
    return 0;
}

