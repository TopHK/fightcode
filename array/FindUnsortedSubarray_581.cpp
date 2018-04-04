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
	int findUnsortedSubarray_v1(vector<int>& nums)
	{
		int size = nums.size();
		if (size <= 1) return 0;
		vector<int> nums2 = nums;
		sort(nums2.begin(), nums2.end());

		int i = 0, j = size - 1;
		while (i < size)
		{
			if (nums[i] == nums2[i]) i++;
			else break;
		}
		while (j >= 0)
		{
			if (nums[j] == nums2[j]) j--;
			else break;
		}
		return (i >= j ? 0 : j - i + 1);
	}

	int findUnsortedSubarray(vector<int>& nums)
	{
		int size = nums.size();
		if (size <= 1) return 0;

		int left = 0, right = -1;
		int maxNum = nums[0];
		int minNum = nums[size-1];
		for (int i = 0; i < size; ++i)
		{
			maxNum = max(maxNum, nums[i]);
			if (nums[i] != maxNum) right = i;
			minNum = min(minNum, nums[size-i-1]);
			if (nums[size - i - 1] != minNum) left = size - i - 1;
		}
		return (right - left + 1);
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
//	cout << solution.findUnsortedSubarray(nums) << endl;
//	return 0;
//}