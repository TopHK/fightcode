/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
*/
#include<iostream>
using namespace std;

int trailingZero(int n)
{
    int count = 0;
    int base = 5;
    while(n >= base)
    {
        count += n / base;
        base *= 5;
    }
    return count;
}

int main()
{
    int n = 25;
    cout<<trailingZero(n)<<endl;
    return 0;
}
