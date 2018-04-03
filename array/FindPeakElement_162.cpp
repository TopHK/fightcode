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
    int findPeakElement_v1(vector<int>& nums)
    {
        int size = nums.size();
        if(size == 1) return 0;
        for(int i = 0; i < size; ++i)
        {
            if(i == 0)
            {
                if(nums[0] > nums[1]) return 0;
            }
            else if(i == size-1)
            {
                if(nums[i] > nums[size-2]) return size-1;
            }
            else if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
    }

    int findPeakElement(vector<int>& nums)
    {
        int size = nums.size();
        if(size == 1) return 0;
        int low = 0;
        int high = size-1;
        while(low < high-1)
        {
            int mid = low + ((high-low) >> 1);
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] > nums[mid-1])
                low = mid+1;
            else if(nums[mid] < nums[mid-1])
                high = mid-1;
        }
        return (nums[low] > nums[high] ? low : high);
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
    vector<int> nums = {1,2,3,1};
    cout<<solution.findPeakElement(nums)<<endl;
    return 0;
}


/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
