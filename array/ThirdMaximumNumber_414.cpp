#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

//int x=[](){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    return 0;
//}();

class Solution
{
public:
    int thirdMax_v1(vector<int>& nums)
    {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;
        int hitCount = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == firstMax || nums[i] == secondMax || nums[i] == thirdMax)
                continue;
            if(nums[i] > firstMax)
            {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
                hitCount++;
            }
            else if(nums[i] > secondMax)
            {
                thirdMax = secondMax;
                secondMax = nums[i];
                hitCount++;
            }
            else if(nums[i] > thirdMax)
            {
                thirdMax = nums[i];
                hitCount++;
            }
        }
        return hitCount >= 3 ? thirdMax : firstMax;
    }
    int thirdMax(vector<int>& nums)
    {
        set<int> maxSet;
        for(int i = 0; i < nums.size(); ++i)
        {
            maxSet.insert(nums[i]);
            if(maxSet.size() > 3) maxSet.erase(maxSet.begin());
        }
        return maxSet.size() == 3 ? *maxSet.begin() : *maxSet.rbegin();
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> nums = {1,2,2,5,3,5};
//    cout<<solution.thirdMax(nums)<<endl;
//    return 0;
//}


/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
