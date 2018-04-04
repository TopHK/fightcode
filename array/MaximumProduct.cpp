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
	int maximumProduct(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int size = nums.size();
		int product1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
		int product2 = nums[0] * nums[1] * nums[size - 1];
		return max(product1, product2);
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 1, 2, 3, 4 };
//	cout << solution.maximumProduct(nums) << endl;
//	return 0;
//}