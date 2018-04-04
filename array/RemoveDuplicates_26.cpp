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
	int removeDuplicates(vector<int>& nums)
	{
		int size = nums.size();
		if (size <= 1) return size;
		int i = 1;
		int currentNum = nums[0];
		for (int j = 1; j < size; ++j)
		{
			if (nums[j] != currentNum)
			{
				nums[i++] = nums[j];
				currentNum = nums[j];
			}
		}
		return i;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 1, 1, 2, 2, 3, 3, 4, 5 };
//	//vector<int> nums = { 1, 1, 1 };
//	cout << solution.removeDuplicates(nums) << endl;
//	return 0;
//}