/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
*/
#include<iostream>
using namespace std;

int sqrt_v1(int x)
{
    int left = 1;
    int right = x;
    while(left < right)
    {
        long long int middle = left + ((right-left)>>1);
        if(middle * middle <= x)
        {
            if((middle+1) * (middle+1) > x) return middle;
            left = middle+1;
        }
        else right = middle-1;
    }
    return left;
}

int sqrt(int x)
{
    int left = 1;
    int right = x;
    while(left < right)
    {
        int middle = left + ((right-left)>>1);
        if(middle <= x/middle)
        {
            if((middle+1) > x /(middle+1)) return middle;
            left = middle+1;
        }
        else right = middle-1;
    }
    return left;
}

int main()
{
    int x = 8;
    cout<<sqrt(x)<<endl;
    return 0;
}
