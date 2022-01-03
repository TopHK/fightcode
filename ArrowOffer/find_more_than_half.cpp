#include<iostream>
#include<vector>
using namespace std;

bool CheckMoreThanHalf(const vector<int>& nums, const int& target) {
    int count = 0;
    for (const auto& num: nums) {
        if (num == target) {
            ++count;
        }
    }
    return count > nums.size() / 2;
}

int FindMoreThanHalf(const vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int target = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == target) {
            ++count;
        } else {
            --count;
        }
        if (count == 0) {
            target = nums[i];
            count = 1;
        }
    }
    target = (CheckMoreThanHalf(nums, target) ? target : -1);
    return target;
}

int Partition(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return left;
    }
    int pivotal = nums[left];
    int i = left, j = right;
    while (i <= j) {
        while (i <= j && nums[i] <= pivotal) {
            ++i;
        }
        while (i <= j && nums[j] > pivotal) {
            --j;
        }
        if (i <= j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    nums[left] = nums[j];
    nums[j] = pivotal;
    return j;
}

int FindMoreThanHalfV2(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int left = 0, right = nums.size()-1;
    int middle = ((right - left) >> 1) + left;
    int target = -1;
    while (left < right) {
        int pos = Partition(nums, left, right);
        if (pos == middle) {
            target = nums[pos];
            break;
        } else if (pos < middle) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    if (!CheckMoreThanHalf(nums, target)) {
        target = -1;
    }
    return target;
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 2, 5, 2, 4, 2};
    cout << FindMoreThanHalf(nums) << endl;
    cout << FindMoreThanHalfV2(nums) << endl;
    return 0;
}