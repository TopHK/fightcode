#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*
 * 1, 3, 1, 2, 3, 3, 1
 * sort: 1, 1, 1, 2, 3, 3, 3
 */
void PrintVector(const vector<int>& nums) {
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int FindSpecialNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    PrintVector(nums);
    int left = 0, right = nums.size()-1;
    while (left < right) {
        int middle = ((right - left) >> 1) + left;
        int right_pos = middle;
        while (right_pos <= right && nums[right_pos] == nums[middle]) {
            ++right_pos;
        }
        int left_size = right_pos - left;
        if ((left_size % 3) != 0) {
            right = (right_pos - 4 < left ? left : right_pos - 4);
        } else {
            left = (right_pos + 3 > right ? right : right_pos + 3);
        }
    }
    return nums[left];
}

int FindSpecialNumberV2(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        int sum_of_one = 0;
        int flag = (1 << i);
        for (const auto& num : nums) {
           if (num & flag) {
               ++sum_of_one;
           }
        }
        if (sum_of_one % 3) {
            result |= flag;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {5, 3, 1, 3, 1, 1, 5, 3, 10, 5};
    cout << FindSpecialNumber(nums) << endl;
    cout << FindSpecialNumberV2(nums) << endl;
    return 0;
}