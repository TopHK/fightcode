#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printVector(vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if(rowIndex < 0) return {};
        vector<vector<int>> result(2);
        result[0].push_back(1);

        int currentIndex = 1;
        int nextIndex = 0;
		for (int i = 1; i <= rowIndex; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j <= (i >> 1))
				{
					int left = (j >= 1 ? result[nextIndex][j - 1] : 0);
					int right = result[nextIndex][j];
					result[currentIndex].push_back(left + right);
				}
				else result[currentIndex].push_back(result[currentIndex][i - j]);
			}
			result[nextIndex].clear();
			currentIndex = 1 - currentIndex;
			nextIndex = 1 - nextIndex;
		}
		return result[nextIndex];
    }
};


int main()
{
    Solution solution;
    int rowIndex = 3;
    vector<int> result = solution.getRow(rowIndex);
    printVector(result);
    return 0;
}


/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

