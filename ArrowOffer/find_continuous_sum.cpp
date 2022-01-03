#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> FindContinuousSum(const int s) {
    vector<vector<int>> results;
    int small = 1, big = 2;
    int current_sum = 3;
    while (small <= (s + 1) / 2) {
//        cout << small << " " << big << " " << current_sum << endl;
        if (current_sum < s) {
            ++big;
            current_sum += big;
        } else if (current_sum > s) {
            current_sum -= small;
            ++small;
        } else {
            vector<int> result;
            for (int i = small; i <= big; ++i) {
                result.push_back(i);
            }
            results.push_back(result);
            current_sum -= small;
            ++small;
        }
    }
    return results;
}

int main() {
    int s = 15;
    vector<vector<int>> results = FindContinuousSum(s);
    for (const auto& result : results) {
        for (const auto& item : result) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}