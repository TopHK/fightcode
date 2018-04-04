#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static int x = [](){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();

class Solution {
public:
	vector<vector<int>> generate(int numRows)
	{
		if (numRows == 0) return {};
		vector<vector<int>> result(numRows);
		result[0] = {1};
		for (int i = 1; i < numRows; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j <= (i >> 1))
				{
					int left = (j >= 1 ? result[i - 1][j - 1] : 0);
					int right = result[i - 1][j];
					result[i].push_back(left + right);
				}
				else result[i].push_back(result[i][i - j]);
			}
		}
		return result;
	}
};

void printVector2D(const vector<vector<int>> &nums)
{
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums[i].size(); ++j)
			cout << nums[i][j] << " ";
		cout << endl;
	}
}

//int main()
//{
//	Solution solution;
//	int nRows = 5;
//	vector<vector<int>> result = solution.generate(5);
//	printVector2D(result);
//	return 0;
//}