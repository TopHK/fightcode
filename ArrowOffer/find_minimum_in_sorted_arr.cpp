#include<iostream>
#include<vector>
using namespace std;

int FindMinimumInSortedArr(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int middle = ((right - left) >> 1) + left;
        if (nums[middle] > nums[right]) {
            left = middle + 1;
        } else if (nums[middle] < nums[right]){
            right = middle;
        } else {
            --right;
        }
    }
    return nums[right];
}

int main() {
    vector<int> nums1 = {6, 8, 9, 11, 2, 5};
    vector<int> nums2 = {2, 5, 6, 8, 9, 11};
    vector<int> nums3 = {2, 5, 6, 2, 2, 2};
    vector<int> nums = {1, 2, 2, 2, 2};
    cout << FindMinimumInSortedArr(nums) << endl;

    return 0;
}