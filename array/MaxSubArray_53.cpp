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
	int maxSubArray(vector<int>& nums)
	{
		int size = nums.size();
		if (size == 0) return 0;
		int maxSum = nums[0];
		int currentSum = 0;
		for (int i = 0; i < size; ++i)
		{
			currentSum += nums[i];
			maxSum = max(currentSum, maxSum);
			currentSum = max(currentSum, 0);
		}
		return maxSum;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
//	//vector<int> nums = { 3, 2, 2, 3 };
//	cout << solution.maxSubArray(nums) << endl;
//	return 0;
//}