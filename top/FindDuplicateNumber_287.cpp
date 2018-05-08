#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[nums[0]];
    while(slow != fast)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    }

    slow = 0;
    while(slow != fast)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

int main()
{
    vector<int> nums = {1, 2, 3, 2};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}
