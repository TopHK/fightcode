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
    int countPalindrom(string &s, int left, int right)
    {
        int totalCount = 0;
        while(left >= 0 && right < s.size() && s[left--] == s[right++])
            totalCount++;
        return totalCount;
    }

    int countSubstrings(string s)
    {
        int size = s.size();
        int count = 0;
        for(int i = 0; i < size; ++i)
        {
            count += countPalindrom(s, i, i);
            count += countPalindrom(s, i, i+1);
        }
        return count;
    }
};

int main()
{
    Solution solution;
    string s = "aba";
    cout<<solution.countSubstrings(s)<<endl;

    string s2 = "aaa";
    cout<<solution.countSubstrings(s2)<<endl;
    return 0;
}


/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
*/
