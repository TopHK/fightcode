#include<iostream>
#include<string>
using namespace std;

void CombinationCore(const string& str, int index, string result, const int &n) {
    if (result.size() == n) {
        cout << result << " ";
        return;
    }
    if (index >= str.size()) {
        return;
    }
    CombinationCore(str, index + 1, result + str[index], n);
    CombinationCore(str, index + 1, result, n);
}

void Combination(const string& str, const int &n) {
    CombinationCore(str, 0, "", n);
}

int main() {
    string str = "abc";
    int n = 1;
    Combination(str, n);
    return 0;
}
