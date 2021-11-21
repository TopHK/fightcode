#include <iostream>
#include <vector>
using namespace std;

int CalculateCountLess(const vector<int>& nums, const int& left, const int& target) {
    int count = 0;
    for (const auto& num : nums) {
        if (num >= left && num <= target) {
            ++count;
        }
    }
    return count;
}

int FindRepeatedNumV2(const vector<int>& nums) {
    int size = nums.size();
    int left = 1, right = size-1;
    while (left <= right) {
        int middle = ((right - left) >> 1) + left;
        int count = CalculateCountLess(nums, left, middle);
        if (left == right) {
            if (count > 1) {
                return left;
            } else {
                break;
            }
        }
        if (count > (middle - left + 1)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 3, 1, 6, 4, 5};
    cout << FindRepeatedNumV2(nums) << endl;
    return 0;
}