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
	int removeElement(vector<int>& nums, int val)
	{
		int size = nums.size();
		if (size == 0) return 0;
		int countVal = 0;
		for (int i = 0; i < size; ++i)
			if (nums[i] == val) countVal++;

		int length = size - countVal;
		if (countVal != 0)
		{
			int currentPos = 0;
			for (int i = 0; i < size; ++i)
			{
				if (nums[i] != val)
					nums[currentPos++] = nums[i];
			}
		}
		return length;
	}
};

//int main()
//{
//	Solution solution;
//	//vector<int> nums = { 3, 6, 1, 0 };
//	vector<int> nums = { 3, 2, 2, 3 };
//	int val = 3;
//	cout << solution.removeElement(nums, val) << endl;
//	return 0;
//}