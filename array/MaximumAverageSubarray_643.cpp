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
	double findMaxAverage(vector<int>& nums, int k)
	{
		long long int maxSum = 0;
		long long int currentSum = 0;
		for (int i = 0; i < k; ++i) maxSum += nums[i];
		currentSum = maxSum;
		
		for (int i = k; i < nums.size(); ++i)
		{
			currentSum = currentSum - nums[i - k] + nums[i];
			if (currentSum > maxSum) maxSum = currentSum;
		}
		return double(maxSum) / double(k);
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 1, 12, -5, -6, 50, 3 };
//	int k = 4;
//	cout<<solution.findMaxAverage(nums, k)<<endl;
//	return 0;
//}