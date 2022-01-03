#include<iostream>
#include<vector>
using namespace std;

int GetMaximumPath(const vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int max_value = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> values(rows, vector<int>(cols, 0));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int up_value = (row > 0 ? values[row-1][col] : 0);
            int left_value = (col > 0 ? values[row][col-1] : 0);
            values[row][col] = matrix[row][col] + max(up_value, left_value);
        }
    }
    return values[rows-1][cols-1];
}

int GetMaximumPathV2(const vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> values(cols,0);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int left_value = (col > 0 ? values[col-1] : 0);
            int up_value = (row > 0 ? values[col] : 0);
            values[col] = max(left_value, up_value) + matrix[row][col];
        }
    }
    return values[cols-1];
}

int main() {
    vector<vector<int>> matrix = {
            {1, 10, 3, 8},
            {12, 2, 9, 6},
            {5, 7, 4, 11},
            {3, 7, 16, 5}
    };
    cout << GetMaximumPath(matrix) << endl;
    cout << GetMaximumPathV2(matrix) << endl;
    return 0;
}