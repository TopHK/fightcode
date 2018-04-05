#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    bool isSDN(int num)
    {
        int origin = num;
        while(num)
        {
            int digit = num % 10;
            if(!digit || (origin % digit)) return false;
            num /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;
        while(left <= right)
        {
            if(isSDN(left)) result.push_back(left);
            left++;
        }
        return result;
    }
};

void printVector(const vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int main()
{
    Solution solution;
    int left = 1, right = 22;
    vector<int> result = solution.selfDividingNumbers(left, right);
    printVector(result);
    return 0;
}


/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input:
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/
