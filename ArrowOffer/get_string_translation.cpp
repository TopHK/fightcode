#include<string>
#include<vector>
#include<iostream>
using namespace std;

void GetStringTranslationCore(const string& num, int index, int& count) {
    if (index >= num.size()) {
        ++count;
        return;
    }
    GetStringTranslationCore(num, index+1, count);
    if (index + 1 < num.size()) {
        string sub_str = num.substr(index, 2);
        if (sub_str >= "10" && sub_str <= "25") {
            GetStringTranslationCore(num, index+2, count);
        }
    }
}

int GetStringTranslation(const string& num) {
    int count = 0;
    GetStringTranslationCore(num, 0, count);
    return count;
}

int GetStringTranslationV2(const string& num) {
    if (num.empty()) {
        return 0;
    }
    int size = num.size();
    vector<int> counts(size, 0);
    counts[size-1] = 1;
    for (int i = size-2; i >= 0; --i) {
        string sub_str = num.substr(i, 2);
        if (sub_str >= "10" && sub_str <= "25") {
            if (i < size - 2) {
                counts[i] += counts[i+2];
            } else {
                counts[i] += 1;
            }
        }
        if (i < size - 1) {
            counts[i] += counts[i+1];
        }
    }
    return counts[0];
}

int main() {
    string num = "12258182934";
    cout << GetStringTranslation(num) << endl;
    cout << GetStringTranslationV2(num) << endl;
    return 0;
}