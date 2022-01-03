#include<iostream>
#include<vector>
#include<set>
using namespace std;

int Partition(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return left;
    }
    int pivotal = nums[left];
    int i = left, j = right;
    while (i <= j) {
        while(i <= j && nums[i] <= pivotal) {
            ++i;
        }
        while(i <= j && nums[j] > pivotal) {
            --j;
        }
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    nums[left] = nums[j];
    nums[j] = pivotal;
    return j;
}

vector<int> FindSmallestNums(vector<int>& nums, const int& k) {
    vector<int> results;
    if (k <= 0 || k > nums.size()) {
        return results;
    }
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int pos = Partition(nums, left, right);
        if (pos == k-1) {
            break;
        } else if (pos < k-1) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    results.insert(results.begin(), nums.begin(), nums.begin() + k);
    return results;
}

void PrintVector(const vector<int>& nums) {
    for (const auto& num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> FindSmallestNumsV2(vector<int>& nums, const int& k) {
    vector<int> results;
    if (k <= 0 || k > nums.size()) {
        return results;
    }
    multiset<int, greater<int>> big_set;
    for (const auto& num:nums) {
        if (big_set.size() < k) {
            big_set.insert(num);
        } else {
            if (num < *(big_set.begin())) {
                big_set.insert(num);
                big_set.erase(big_set.begin());
            }
        }
    }
    results.insert(results.begin(), big_set.begin(), big_set.end());
    return results;
}

int main() {
    vector<int> nums = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 6;
//    vector<int> results = FindSmallestNums(nums, k);
    vector<int> results = FindSmallestNumsV2(nums, k);
    PrintVector(results);
    return 0;
}