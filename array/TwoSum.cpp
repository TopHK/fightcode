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
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		int size = nums.size();
		vector<int> nums2 = nums;
		sort(nums2.begin(), nums2.end());
		int left = 0, right = size - 1;
		while (left < right)
		{
			int sum = nums2[left] + nums2[right];
			if (sum > target) right--;
			else if (sum < target) left++;
			else break;
		}
		if (left >= right) return result;

		int index1 = -1, index2 = -1;
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] == nums2[left] || nums[i] == nums2[right])
			{
				if (index1 == -1) index1 = i;
				else if (index2 == -1) index2 = i;
				if (index1 != -1 && index2 != -1)
				{
					result.push_back(index1);
					result.push_back(index2);
					cout << index1 << " " << index2 << endl;
					break;
				}
			}
		}
		return result;
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 2, 7, 11, 15 };
//	int target = 9;
//	solution.twoSum(nums, target);
//	return 0;
//}