#include<string>
#include<iostream>
#include<map>
using namespace std;

string solve(int M, int N) {
    map<int, string> table = {
            {10, "A"},
            {11, "B"},
            {12, "C"},
            {13, "D"},
            {14, "E"},
            {15, "F"}
    };
    string result;
    bool is_minus = (M < 0);
    M = static_cast<int>(abs(M));
    while (M) {
        int res = M % N;
        M /= N;
        if (table.count(res)) {
            result = table[res] + result;
        } else {
            result = to_string(res) + result;
        }
    }
    if (is_minus) {
        result = "-" + result;
    }
    return result;
}

int main() {
    int M = -10, N = 2;
    cout << solve(M, N) << endl;
    return 0;
}