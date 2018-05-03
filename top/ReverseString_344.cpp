#include<iostream>
#include<algorithm>
using namespace std;

/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

class Solution
{
public:
    string reverseString_v1(string s)
    {
        reverse(s.begin(), s.end());
        return s;
    }

    string reverseString(string s)
    {
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string s("hello world!");
    cout<<solution.reverseString(s)<<endl;
    return 0;
}
