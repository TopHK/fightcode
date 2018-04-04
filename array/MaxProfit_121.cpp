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
	int maxProfit(vector<int>& prices)
	{
		int size = prices.size();
		if (size < 2) return 0;
		int minNum = prices[0];
		int currentProfit = 0;
		for (int i = 1; i < size; ++i)
		{
			if (prices[i] - minNum > currentProfit)
				currentProfit = prices[i] - minNum;
			minNum = min(minNum, prices[i]);
		}
		return currentProfit;
	}
};

//int main()
//{
//	Solution solution;
//	//vector<int> nums = { 7, 1, 5, 3, 6, 4 };
//	vector<int> nums = { 7, 6, 4, 3, 1};
//	cout << solution.maxProfit(nums) << endl;
//	return 0;
//}