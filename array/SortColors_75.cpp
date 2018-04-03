#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    void sortColors_v1(vector<int>& nums)
    {
        int redCount = 0;
        int whiteCount = 0;
        int blueCount = 0;
        int size = nums.size();
        for(int i = 0; i < size; ++i)
        {
            if(nums[i] == 0) redCount++;
            else if(nums[i] == 1) whiteCount++;
            else if(nums[i] == 2) blueCount++;
        }
        for(int i = 0; i < size; ++i)
        {
            if(i < redCount) nums[i] = 0;
            else if(i < redCount+whiteCount) nums[i] = 1;
            else nums[i] = 2;
        }
    }

    void sortColors(vector<int>& nums)
    {
        int size = nums.size();
        int lowPos = 0;
        int highPos = size - 1;
        int i = 0;
        while(i <= highPos)
        {
            if(nums[i] == 0)
            {
                int temp = nums[i];
                nums[i] = nums[lowPos];
                nums[lowPos] = temp;
                lowPos++;
                i++;
            }
            else if(nums[i] == 2)
            {
                int temp = nums[i];
                nums[i] = nums[highPos];
                nums[highPos] = temp;
                highPos--;
            }
            else if(nums[i] == 1) i++;
        }
    }
};

void printVector(const vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Solution solution;
    vector<int> nums = {2, 1, 0, 1};
    solution.sortColors(nums);
    printVector(nums);
    return 0;
}


/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
