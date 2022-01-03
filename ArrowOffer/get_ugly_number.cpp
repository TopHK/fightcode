#include<iostream>
#include<vector>
using namespace std;

int GetUglyNumber(const int k) {
    if (k <= 0) {
        return -1;
    }
    vector<int> ugly_nums = {2, 3, 4, 5};
    if (k <= 4) {
        return ugly_nums[k-1];
    }
    int current_ugly_num = 5;
    for (int i = 5; i <= k; ++i) {
        int num2 = 1, num3 = 1, num5 = 1;
        for (const auto& num:ugly_nums) {
            if (num * 2 > current_ugly_num) {
                num2 = num * 2;
                break;
            }
        }
        for (const auto& num:ugly_nums) {
            if (num * 3 > current_ugly_num) {
                num3 = num * 3;
                break;
            }
        }
        for (const auto& num:ugly_nums) {
            if (num * 5 > current_ugly_num) {
                num5 = num * 5;
                break;
            }
        }
        current_ugly_num = min(min(num2, num3), num5);
        ugly_nums.push_back(current_ugly_num);
    }
    return ugly_nums.back();
}

int GetUglyNumberV2(const int k) {
    if (k <= 0) {
        return -1;
    }
    vector<int> ugly_numbers(k+1, 1);
    int ugly_2 = 0, ugly_3 = 0, ugly_5 = 0;
    for (int i = 1; i <= k; ++i) {
        int next_ugly_number = min(min(ugly_numbers[ugly_2] * 2, ugly_numbers[ugly_3] * 3), ugly_numbers[ugly_5] * 5);
        ugly_numbers[i] = next_ugly_number;
        while (ugly_numbers[ugly_2] * 2 <= next_ugly_number) {
            ++ugly_2;
        }
        while (ugly_numbers[ugly_3] * 3 <= next_ugly_number) {
            ++ugly_3;
        }
        while (ugly_numbers[ugly_5] * 5 <= next_ugly_number) {
            ++ugly_5;
        }
    }
    return ugly_numbers[k];
}

int main() {
    for (int k = 1; k < 30; ++k) {
        cout << GetUglyNumber(k) << " " << GetUglyNumberV2(k) << endl;
    }
    return 0;
}