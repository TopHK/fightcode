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
	int findLengthOfLCIS(vector<int>& nums)
	{
		int size = nums.size();
		if (size < 2) return size;
		int length = 1;
		int minPos = 0, maxPos = 0;
		for (int i = 1; i < size; ++i)
		{
			if (nums[i] > nums[i - 1])
			{
				maxPos++;
				length = max(length , maxPos - minPos + 1);
			}
			else
			{
				minPos = i;
				maxPos = i;
			}
		}
		return length;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 2,2,2,2,2 };
//	//vector<int> nums = { 1, 3, 5, 4, 7 };
//	cout << solution.findLengthOfLCIS(nums) << endl;
//	return 0;
//}