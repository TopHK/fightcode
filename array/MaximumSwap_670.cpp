#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<math.h>
#include<string>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int maximumSwap_v1(int num)
    {
        int maxNum = 0;  // 最大值的数字
        int maxPos = -1; // 最大值的位序
        int leftNum = 0;  // 高位的数字
        int leftPos = 0;  // 高位的位序
        int rightNum = 0; // 最右边真正要交换的数字
        int rightPos = 0;  // 最右边真正要交换的位序

        // 查找所有位中最大的数字，以及位序
        int temp = num; // 备份num
        int pos = 0;    // 遍历过程中的位序
        int digit = 0;  // 遍历过程每一位的数
        while(temp)
        {
            pos++;
            digit = temp % 10;
            if(digit > maxNum)
            {
                maxPos = pos;
                maxNum = digit;
            }
            else if (digit < maxNum)
            {
                leftPos = pos;
                leftNum = digit;
                rightPos = maxPos;
                rightNum = maxNum;
            }
            temp /= 10;
        }
        cout<<leftPos<<" "<<leftNum<<" "<<rightPos<<" "<<rightNum<<endl;
        int result = num;  // 变换后的数字
        if(leftPos > rightPos && rightNum >leftNum) // 交换条件：不在同一位置，且交换的数字大于高位的数字
        {
            result += (leftNum - rightNum) * (int)pow(10, rightPos-1);
            result += (rightNum - leftNum) * (int)pow(10, leftPos-1);
        }
        return result;
    }

    int maximumSwap(int num)
    {
        string data = to_string(num);
        int size = data.size();

        int rightPos = size-1;
        int leftPos = size-1;
        int maxPos = size-1;
        char maxCh = '0';
        for(int i = size-1; i >= 0; --i)
        {
            if(data[i] > maxCh)
            {
                maxPos = i;
                maxCh = data[i];
                continue;
            }
            if(data[i] < maxCh)
            {
                leftPos = i;
                rightPos = maxPos;
            }
        }
        swap(data[leftPos], data[rightPos]);
        return stoi(data);
    }
};

void printVector(const vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Solution solution;
    int num = 2736;
    int num2 = 9973;
    int num3 = 1000;
    int num4 = 1020;
    int num5 = 98368;
    cout<<solution.maximumSwap_v1(num5)<<endl;
    return 0;
}


/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/
