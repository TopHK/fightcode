#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int size = matrix.size();
        if(size <= 1) return;

        for(int i = 0; i < size/2; ++i)
        {
            for(int j = i; j < size-i-1; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[size-1-j][i];
                matrix[size-1-j][i] = matrix[size-i-1][size-1-j];
                matrix[size-i-1][size-1-j] = matrix[j][size-1-i];
                matrix[j][size-1-i] = temp;
            }
        }
    }
};

void printVector2D(vector<vector<int>> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = 0; j < nums[i].size(); ++j)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    Solution solution;
//    vector<vector<int> > matrix = {
//      {1,2,3},
//      {4,5,6},
//      {7,8,9}
//    };

    vector<vector<int> > matrix = {
      {5, 1, 9,11},
      {2, 4, 8,10},
      {13, 3, 6, 7},
      {15,14,12,16}
    };
    solution.rotate(matrix);
    printVector2D(matrix);
    return 0;
}


/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
