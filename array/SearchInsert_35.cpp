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
	int searchInsert(vector<int>& nums, int target)
	{
		int size = nums.size();
		int begin = 0, end = size - 1;
		while (begin <= end)
		{
			int mid = begin + ((end - begin) >> 1);
			if (nums[mid] < target) begin = mid + 1;
			else end = mid - 1;
		}
		return begin;
	}
};

//int main()
//{
//	Solution solution;
//	//vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
//	vector<int> nums = { 1,3,5,6 };
//	int target = 5;
//	cout << solution.searchInsert(nums, target) << endl;
//	return 0;
//}