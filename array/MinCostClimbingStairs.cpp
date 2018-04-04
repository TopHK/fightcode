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
	int minCostClimbingStairs(vector<int>& cost)
	{
		int totalCost1 = cost[0];
		int totalCost2 = cost[1];
		int totalCost3 = cost[1];
		for (int i = 2; i < cost.size(); ++i)
		{
			totalCost3 = cost[i] + min(totalCost1, totalCost2);
			totalCost1 = totalCost2;
			totalCost2 = totalCost3;
		}
		return min(totalCost1, totalCost2);
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
//	//vector<int> nums = { 10, 15, 20};
//	cout << solution.minCostClimbingStairs(nums) << endl;
//	return 0;
//}