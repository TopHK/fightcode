#include<vector>
#include<iostream>
using namespace std;

int minPathSum(vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                matrix[i][j] += matrix[i][j-1];
            } else if (j == 0) {
                matrix[i][j] += matrix[i-1][j];
            } else {
                matrix[i][j] += min(matrix[i][j-1], matrix[i-1][j]);
            }
        }
    }
    return matrix.back().back();
}

int main() {
    vector<vector<int>> matrix = {
            {1,3,5,9},
            {8,1,3,4},
            {5,0,6,1},
            {8,8,4,0}
    };
    cout << minPathSum(matrix) << endl;
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}

