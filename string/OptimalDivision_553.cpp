#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    string optimalDivision(vector<int>& nums)
    {
        string expression;
        int sizeOfNum = nums.size();
        expression += to_string(nums[0]);
        if(sizeOfNum == 1) return expression;
        expression += "/";
        if(sizeOfNum == 2) return expression + to_string(nums[1]);

        expression += "(";
        for(int i = 1; i < sizeOfNum; ++i)
        {
            if(i != 1) expression += "/";
            expression += to_string(nums[i]);
        }
        expression += ")";
        return expression;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1000,100};
    cout<<solution.optimalDivision(nums)<<endl;
    return 0;
}


/*

Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations.
You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant,
since they don't influence the operation priority. So you should return "1000/(100/10/2)".

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
Note:

The length of the input array is [1, 10].
Elements in the given array will be in range [2, 1000].
There is only one optimal division for each test case.
*/
