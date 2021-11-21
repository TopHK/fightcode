#include <iostream>
#include <vector>
using namespace std;

bool find_in_sorted_matrix(const vector<vector<int>>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int rows = nums.size();
    int cols = nums[0].size();
    int row_id = 0;
    int col_id = cols - 1;
    while (row_id <= rows-1 && col_id >= 0) {
        if (nums[row_id][col_id] == target) {
            return true;
        } else if(nums[row_id][col_id] > target) {
            --col_id;
        } else {
            ++row_id;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> nums = {
            {1, 2, 8, 9},
            {2, 4, 9, 12},
            {4, 7, 10, 13},
            {6, 8, 11, 15}
    };
    int target = 5;
    cout << find_in_sorted_matrix(nums, target) << endl;
    return 0;
}
