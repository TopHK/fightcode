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
	int pivotIndex(vector<int>& nums)
	{
		int size = nums.size();
		if (size == 0) return -1;
		if (size == 1) return 0;
		vector<int> leftSumArray(size, 0);
		vector<int> rightSumArray(size, 0);
		int leftSum = 0;
		for (int i = 0; i < size; ++i)
		{
			leftSum += nums[i];
			leftSumArray[i] = leftSum;
		}
		int rightSum = 0;
		for (int i = size-1; i >= 0; --i)
		{
			rightSum += nums[i];
			rightSumArray[i] = rightSum;
		}
		for (int i = 0; i < size; ++i)
		{
			if (leftSumArray[i] == rightSumArray[i])
				return i;
		}
		return -1;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 1, 7, 3, 6, 5, 6 };
//	cout<< solution.pivotIndex(nums) << endl;
//	return 0;
//}