#include<iostream>
#include<vector>
using namespace std;

int FindInvertedPairsCore(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return 0;
    }
    if (right == left + 1) {
        if (nums[left] > nums[right]) {
            swap(nums[left], nums[right]);
            return 1;
        } else {
            return 0;
        }
    }
    int middle = ((right - left) >> 1) + left;
    int left_count = FindInvertedPairsCore(nums, left, middle);
    int right_count = FindInvertedPairsCore(nums, middle+1, right);
    int mix_count = 0;
    vector<int> combined_vec(right - left + 1, 0);
    int i = middle, j = right;
    int k = right - left;
    while (i >= left || j >= middle+1) {
        if (i >= left && j >= middle+1) {
            if (nums[i] > nums[j]) {
                combined_vec[k--] = nums[i--];
                mix_count += (j - middle);
            } else {
                combined_vec[k--] = nums[j--];
            }
        } else if (i >= left) {
            combined_vec[k--] = nums[i--];
        } else {
            combined_vec[k--] = nums[j--];
        }
    }
    for (i = left, k = 0; i <= right; ++i, ++k) {
        nums[i] = combined_vec[k];
    }
    return left_count + right_count + mix_count;
}

int FindInvertedPairs(vector<int>& nums) {
    if (nums.size() <= 1) {
        return 0;
    }
    return FindInvertedPairsCore(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {11, 10, 9, 12};
    cout << FindInvertedPairs(nums) << endl;
    return 0;
}