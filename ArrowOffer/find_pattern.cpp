#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PrintVector(const vector<int>& nums) {
    for (const auto & num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> GetNext(const string& str) {
    int size = str.size();
    vector<int> next(size, -1);
    int k = -1, j = 0;
    while (j < size-1) {
        if (k == -1 || str[k] == str[j]) {
            next[++j] = ++k;
        } else {
            k = next[k];
        }
    }
    return next;
}

int FindPattern(const string& str1, const string& str2) {
    if (str1.empty() || str2.empty()) {
        return -1;
    }
    vector<int> next = GetNext(str2);
    PrintVector(next);
    int i = 0, j = 0;
    int size1 = str1.size(), size2 = str2.size();
    while (i < size1 && j < size2) {
        if (j == -1 || str1[i] == str2[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == str2.size()) {
        return i - str2.size();
    } else {
        return -1;
    }
}

int main() {
    string str1 = "hereisasimpleexample";
    string pattern = "isa";
//    vector<int> next = GetNext(pattern);
//    PrintVector(next);
    cout << FindPattern(str1, pattern) << endl;
    return 0;
}