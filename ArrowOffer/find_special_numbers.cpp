#include<vector>
#include<iostream>
using namespace std;

int FindSpecialNumbers(const vector<int>& nums) {
    int result = 0;
    for (const auto& num : nums) {
        result ^= num;
    }
    return result;
}

vector<int> FindSpecialNumbersV2(const vector<int>& nums) {
    int flag = 0;
    for (const auto& num : nums) {
        flag ^= num;
    }
    int result1 = 0, result2 = 0;
    for (int i = 0; i < 32; ++i) {
        int is_bit_one = flag & (1 << i);
        if(is_bit_one) {
            for (const auto& num : nums) {
                if ((num & (1 << i)) == is_bit_one) {
                    result1 ^= num;
                } else {
                    result2 ^= num;
                }
            }
            break;
        }
    }
    return {result1, result2};
}

int main() {
//    vector<int> nums = {1, 5, 3, 5, 8, 1, 3};
//    cout << FindSpecialNumbers(nums) << endl;

    vector<int> nums = {2, 3, 5, 3, 2, 1, 8, 9, 9, 8};
    vector<int> results = FindSpecialNumbersV2(nums);
    for (const auto& num : results) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}