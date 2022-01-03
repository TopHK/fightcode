#include<iostream>
#include<vector>
using namespace std;

void PrintVector(const vector<int>& nums) {
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout <<endl;
}

int Get_LIS(vector<int>& arr) {
    if (arr.size() < 2) {
        return arr.size();
    }
    vector<int> result;
    vector<int> increasing_len(arr.size() + 1, -1);
    int max_len = 1;
    increasing_len[1] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] >= increasing_len[max_len]) {
            increasing_len[++max_len] = arr[i];
        } else {
            int len = lower_bound(increasing_len.begin() + 1, increasing_len.begin() + max_len + 1, arr[i]) - increasing_len.begin();
            increasing_len[len] = arr[i];
        }
    }
    return max_len;
}

vector<int> Get_LIS_V2(vector<int>& arr) {
    if (arr.size() < 2) {
        return arr;
    }
    vector<int> increasing_len;  // LIS序列长度为index，value是以index长度的序列最后一个元素大小
    increasing_len.emplace_back(arr[0]);
    vector<int> dp;  // index为序列的最后一个元素的index, value是对应序列的长度
    dp.emplace_back(1);
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > increasing_len.back()) {
            increasing_len.emplace_back(arr[i]);
            dp.emplace_back(increasing_len.size());
        } else {
            int len = lower_bound(increasing_len.begin(), increasing_len.end(), arr[i]) - increasing_len.begin();
            increasing_len[len] = arr[i];
            dp.emplace_back(len + 1);
        }
    }
    for (int j = arr.size(), k = increasing_len.size() - 1; k >= 0; --j) {
        if (dp[j] == k + 1) {
            increasing_len[k] = arr[j];
            --k;
        }
    }
    return increasing_len;
}

int main() {
    vector<int> arr = {2, 5, 3, 4, 1, 7, 6, 3, 8, 2, 11, 10};
    cout << Get_LIS(arr) << endl;
    vector<int> result = Get_LIS_V2(arr);
    PrintVector(result);
    return 0;
}