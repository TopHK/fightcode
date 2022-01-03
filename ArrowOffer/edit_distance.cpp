#include<iostream>
#include<vector>
using namespace std;

int minEditCost(string str1, string str2, int ic, int dc, int rc) {
    if (str1.empty() || str2.empty()) {
        return max(str1.size(), str2.size()) * ic;
    }
    vector<vector<int>> distances(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for (int i = 1; i <= str1.size(); ++i) {
        distances[i][0] = i * dc;
    }
    for (int j = 1; j <= str2.size(); ++j) {
        distances[0][j] = j * ic;
    }
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i-1] == str2[j-1]) {
                distances[i][j] = distances[i-1][j-1];
            } else {
                distances[i][j] = min(min(distances[i-1][j] + dc,
                                          distances[i][j-1] + ic),
                                      distances[i-1][j-1] + rc);
            }
        }
    }
    return distances.back().back();
}

int EditDistance(string str1, string str2) {
    if (str1.empty() || str2.empty()) {
        return max(str1.size(), str2.size());
    }
    vector<vector<int>> distances(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for (int i = 1; i <= str1.size(); ++i) {
        distances[i][0] = i;
    }
    for (int j = 1; j <= str2.size(); ++j) {
        distances[0][j] = j;
    }
    for (int i = 1; i <= str1.size(); ++i) {
        for (int j = 1; j <= str2.size(); ++j) {
            if (str1[i-1] == str2[j-1]) {
                distances[i][j] = distances[i-1][j-1];
            } else {
                distances[i][j] = 1 + min(min(distances[i-1][j], distances[i][j-1]),
                                          distances[i-1][j-1]);
            }
        }
    }
    return distances.back().back();
}

int main() {
    string str1 = "abc";
    string str2 = "adc";
    int ic = 5, dc = 3, rc = 2;
    cout << minEditCost(str1, str2, ic, dc, rc) << endl;
//    cout << EditDistance(str1, str2) << endl;
    return 0;
}