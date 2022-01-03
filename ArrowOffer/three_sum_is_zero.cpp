#include<iostream>
#include<vector>
using namespace std;

void PrintVector(const vector<vector<int>>& nums) {
    for (const auto & row : nums) {
        for (const auto & cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> ThreeSum(vector<int> &num) {
    vector<vector<int>> results;
    if (num.size() < 3) {
        return results;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i <= num.size()-3; ++i) {
        if (num[i] > 0) {
            break;
        }
        if (i > 0 && num[i] == num[i-1]) {
            continue;
        }
        int target = -num[i];
        int left = i + 1, right = num.size()-1;
        while (left < right) {
            if (left > i + 1 && num[left] == num[left-1]) {
                ++left;
                continue;
            }
            int sum = num[left] + num[right];
            if (sum == target) {
                results.push_back({num[i], num[left], num[right]});
                ++left;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return results;
}

int main() {
    vector<int> nums = {0, -10, -10, -8, 4, 5, 5, 6, 5, 8};
    vector<vector<int>> results = ThreeSum(nums);
    PrintVector(results);
    return 0;
}
