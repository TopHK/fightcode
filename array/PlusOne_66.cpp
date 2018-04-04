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
	vector<int> plusOne(vector<int>& digits)
	{
		int size = digits.size();
		bool shift = true;
		for (int i = 0; i < size; ++i)
			if (digits[i] != 9)
			{
				shift = false;
				break;
			}
		vector<int> result(size, 0);
		if (shift) result.push_back(0);
		int currentIndex = result.size() - 1;
		int shiftFlag = 1;
		for (int i = size - 1; i >= 0; --i)
		{
			int digit = digits[i] + shiftFlag;
			if (digit < 10)
			{
				shiftFlag = 0;
				result[currentIndex] = digit;
			}
			else
			{
				shiftFlag = 1;
				result[currentIndex] = 0;
			}
			currentIndex--;
		}
		if (shiftFlag) result[0] = 1;
		return result;
	}
};

void printVector(const vector<int> &nums)
{
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
}

//int main()
//{
//	Solution solution;
//	//vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
//	vector<int> nums = { 1, 3, 5, 6 };
//	printVector(solution.plusOne(nums));
//	return 0;
//}