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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = m-1, j = n-1;
		int currentPos = m+n-1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] >= nums2[j])
			{
				nums1[currentPos--] = nums1[i];
				i--;
			}
			else
			{
				nums1[currentPos--] = nums2[j];
				j--;
			}
		}
		if (j >= 0)
		{
			while (j >= 0)
			{
				nums1[j] = nums2[j];
				j--;
			}
		}
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums1 = { 1, 2, 3, 4, 5 };
//	vector<int> nums2 = { 1, 1, 1 };
//	solution.merge(nums1, nums1.size(), nums2, nums2.size());
//	return 0;
//}