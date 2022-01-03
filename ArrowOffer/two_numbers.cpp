#include<vector>
#include<iostream>
using namespace std;

vector<int> FindTwoNumbers(const vector<int>& nums, const int sum) {
    vector<int> results;
    if (nums.size() <= 1) {
        return results;
    }
    int left = 0, right = nums.size()-1;
    while (left < right) {
        int current_sum = nums[left] + nums[right];
        if (current_sum < sum) {
            ++left;
        } else if (current_sum > sum) {
            --right;
        } else {
            results.push_back(nums[left]);
            results.push_back(nums[right]);
            break;
        }
    }
    return results;
}

int main() {
    vector<int> nums = {3, 2, 6, 7, 8, 9};
    int sum = 13;
    vector<int> results = FindTwoNumbers(nums, sum);
    cout << results[0] << " " << results[1] << endl;
    return 0;
}