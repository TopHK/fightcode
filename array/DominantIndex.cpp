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
	int dominantIndex(vector<int>& nums)
	{
		int size = nums.size();
		if (size == 0) return -1;
		if (size == 1) return 0;
		int maxIndex = 0;
		int maxIndex2 = 0;
		if (nums[0] < nums[1]) maxIndex = 1;
		else maxIndex2 = 1;
		for (int i = 2; i < size; ++i)
		{
			if (nums[i] > nums[maxIndex])
			{
				maxIndex2 = maxIndex;
				maxIndex = i;
			}
			else if (nums[i] > nums[maxIndex2])
			{
				maxIndex2 = i;
			}
		}
		if ((nums[maxIndex] >> 1) >= nums[maxIndex2])
			return maxIndex;
		else return -1;
	}
};

//int main()
//{
//	Solution solution;
//	//vector<int> nums = { 3, 6, 1, 0 };
//	vector<int> nums = { 1, 2, 3, 4 };
//	cout << solution.dominantIndex(nums) << endl;
//	return 0;
//}