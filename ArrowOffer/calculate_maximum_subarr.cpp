#include<iostream>
#include<vector>
using namespace std;

int CalculateMaximum(const vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    int max_sum = nums[0];
    int cur_sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (cur_sum <= 0) {
            cur_sum = nums[i];
        } else {
            cur_sum += nums[i];
        }
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
    }
    return max_sum;
}

int main() {
    vector<int> nums = {1, -2, 3, 10, -4, 7, 2, -5};
    cout << CalculateMaximum(nums) << endl;
    return 0;
}