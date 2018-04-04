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
	bool canPlaceFlowers(vector<int>& flowerbed, int n)
	{
		for (int i = 0; i < flowerbed.size() && n != 0; ++i)
		{
			int leftValue = (i > 0 ? flowerbed[i-1] : 0);
			int rightValue = (i < flowerbed.size()-1 ? flowerbed[i+1] : 0);
			if (leftValue == 0 && rightValue == 0 && flowerbed[i] == 0)
			{
				flowerbed[i] = 1;
				n--;
			}
		}
		return (n == 0);
	}
};

//int main()
//{
//	Solution solution;
//	vector<int> nums1 = { 1, 0, 0, 0, 1 };
//	int n = 1;
//	if(solution.canPlaceFlowers(nums1, n)) cout<<"Yes"<<endl;
//	else cout << "No" << endl;
//	return 0;
//}