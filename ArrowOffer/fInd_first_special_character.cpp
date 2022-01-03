#include<iostream>
#include<string>
#include<vector>
using namespace std;

char FindFirstSpecialCharacter(const string& str) {
    vector<int> counts(256, 0);
    for (const auto& ch:str) {
        ++counts[ch];
    }
    for (const auto& ch:str) {
        if (counts[ch] == 1) {
            return ch;
        }
    }
    return NULL;
}

int main() {
    string str = "abaccdeff";
    cout << FindFirstSpecialCharacter(str) << endl;
    return 0;
}