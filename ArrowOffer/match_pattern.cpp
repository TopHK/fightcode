#include<iostream>
#include<string>
using namespace std;

//bool MatchPatternCore(const string& str, const string& pattern, int i, int j) {
//    if (i >= str.size()) {
//        if (j >= pattern.size()) {
//            return true;
//        } else {
//            if (pattern.size() >= 2 && pattern[1] == '*') {
//                return MatchPatternCore(str, pattern, i, j+2);
//            } else {
//                return false;
//            }
//        }
//    }
//    if (j >= pattern.size()) {
//        return false;
//    }
//
//    if (j <= pattern.size()-2 && pattern[j+1] == '*') {
//        bool found = MatchPatternCore(str, pattern, i, j+2);
//        if (!found) {
//            if (str[i] == pattern[j] || pattern[j] == '.') {
//                return MatchPatternCore(str, pattern, i+1, j+2);
//            } else {
//                return false;
//            }
//        }
//    } else if (str[i] == pattern[j] || pattern[j] == '.') {
//        return MatchPatternCore(str, pattern, i+1, j+1);
//    } else {
//        return false;
//    }
//}

bool MatchPatternCore(const string& str, const string& pattern, int i, int j) {
    if (j >= pattern.size()) {
        return i >= str.size();
    }

    if (j <= pattern.size()-2 && pattern[j+1] == '*') {
        if (MatchPatternCore(str, pattern, i, j+2)) {
            return true;
        } else if (i < str.size() && (str[i] == pattern[j] || pattern[j] == '.')) {
            return MatchPatternCore(str, pattern, i+1, j+2) || MatchPatternCore(str, pattern, i+1, j);
        } else {
            return false;
        }
    } else if (i < str.size() && (str[i] == pattern[j] || pattern[j] == '.')) {
        return MatchPatternCore(str, pattern, i+1, j+1);
    } else {
        return false;
    }
}

bool MatchPattern(const string& str, const string& pattern) {
    return MatchPatternCore(str, pattern, 0, 0);
}

int main() {
    string str = "aaaaa";
    string pattern = "aa.*a";
    cout << MatchPattern(str, pattern) << endl;

    return 0;
}