#include<iostream>
#include<string>
#include<vector>
using namespace std;

int GetLongestPalindrome(string s) {
    if (s.size() <= 1) {
        return s.size();
    }
    string str = "#";
    for (int i = 0; i < s.size(); ++i) {
        str += s[i];
        str += '#';
    }
    cout << str << endl;
    int size = str.size();
    vector<int> rl_vec(size, 1);
    int pos = 0;
    int max_right = 0;
    int max_len = 0;
    for (int i = 0; i < size; ++i) {
        if (i < max_right) {
            rl_vec[i] = min(max_right - i, rl_vec[2 * pos - i]);
        }
        while (i - rl_vec[i] >= 0 && i + rl_vec[i] < size && str[i-rl_vec[i]] == str[i + rl_vec[i]]) {
            ++rl_vec[i];
        }
        if (rl_vec[i] > max_right) {
            max_right = rl_vec[i];
            pos = i;
        }
        max_len = max(max_len, rl_vec[i]);
    }
    return max_len - 1;
}

int main() {
    string str = "deabac";
    cout << GetLongestPalindrome(str) << endl;
    return 0;
}