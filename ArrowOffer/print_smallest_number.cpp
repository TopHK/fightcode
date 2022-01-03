#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int num1, int num2) {
    string str1 = to_string(num1) + to_string(num2);
    string str2 = to_string(num2) + to_string(num1);
    return str1 <= str2;
}

string GetSmallestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), compare);
    string result;
    for (const auto& num:nums) {
        result += to_string(num);
    }
    return result;
}

int main() {
    vector<int> nums = {3, 12, 321};
    cout << GetSmallestNumber(nums) << endl;
    return 0;
}