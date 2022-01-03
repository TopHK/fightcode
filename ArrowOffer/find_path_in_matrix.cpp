#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool JudgePathCore(const vector<vector<char>>& matrix, const string& path, int row, int col, int index, vector<vector<bool>>& visited) {
    if (index > path.size()-1) {
        return true;
    }
    if (row >= matrix.size() || row < 0 || col >= matrix[0].size() || col < 0) {
        return false;
    }
    if (visited[row][col] || matrix[row][col] != path[index]) {
        return false;
    }
    visited[row][col] = true;
    bool has_path = JudgePathCore(matrix, path, row, col-1, index+1, visited) ||
        JudgePathCore(matrix, path, row, col+1, index+1, visited) ||
        JudgePathCore(matrix, path, row-1, col, index+1, visited) ||
        JudgePathCore(matrix, path, row+1, col, index+1, visited);
    if (!has_path) {
        visited[row][col] = false;
    }
    return has_path;
}

bool JudgePath(const vector<vector<char>>& matrix, const string& path) {
    if (matrix.empty()) {
        return false;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (JudgePathCore(matrix, path, row, col, 0, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> matrix = {
            {'a', 'b', 't', 'g'},
            {'c', 'f', 'c', 's'},
            {'j', 'd', 'e', 'h'}
    };
    string path = "jdehsc";
    cout << JudgePath(matrix, path) << endl;
    return 0;
}
