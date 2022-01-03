#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool JudgeUnsignedInteger(const string& str, int& index) {
    // [0-9]
    int before = index;
    while(index < str.size()) {
        if (str[index] >= '0' && str[index] <= '9') {
            ++index;
        } else {
            break;
        }
    }
    return index > before;
}

bool JudgeInteger(const string& str, int& index) {
    // +- sign
    if (str[index] == '+' || str[index] == '-') {
        ++index;
    }
    return JudgeUnsignedInteger(str, index);
}

bool JudgeNumericString(const string& str) {
    if (str.empty()) {
        return false;
    }
    int index = 0;
    // integer part: +32
    bool is_numeric = JudgeInteger(str, index);

    // dot character
    if (str[index] == '.') {
        ++index;
        // valid: +[0-9].[0-9]
        is_numeric = JudgeUnsignedInteger(str, index) || is_numeric;
    }

    if (str[index] == 'e' || str[index] == 'E') {
        ++index;
        // valid: +[0-9].[0-9]e-2
        is_numeric = is_numeric && JudgeInteger(str, index);
    }
    return is_numeric && index >= str.size();
}

int main() {
    vector<string> strs = {
            "+100", "5e2", "-123", "3.1416", "-1E-16", "12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"
    };
    for (const auto& str: strs) {
        cout << str << " " << JudgeNumericString(str) << endl;
    }

    return 0;
}