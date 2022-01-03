#include<iostream>
#include<vector>
using namespace std;

int get_digit_count(int num) {
    int count = 0;
    while(num) {
        count += (num % 10);
        num /= 10;
    }
    return count;
}

int GetAreaCore(const int& m, const int& n, const int& k, int i, int j, vector<vector<bool>>& visited) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }
    if (visited[i][j] || get_digit_count(i) + get_digit_count(j) > k) {
        return 0;
    }
    visited[i][j] = true;
    return 1 + GetAreaCore(m, n, k, i, j-1, visited) +
            GetAreaCore(m, n, k, i, j+1, visited) +
            GetAreaCore(m, n, k, i-1, j, visited) +
            GetAreaCore(m, n, k, i+1, j, visited);

}

int GetArea(const int& m, const int& n, const int& k) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    return GetAreaCore(m, n, k, 0, 0, visited);
}

