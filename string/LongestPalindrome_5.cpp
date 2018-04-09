#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string findPalindrome(const string &s, int left, int right)
    {
        string result;
        while(left >= 0 && right < s.size())
        {
            if(s[left] != s[right]) break;
            left++;
            right--;
        }
    }

    string longestPalindrome(string s)
    {

    }
};

int main()
{
    Solution solution;
//    string path = "/a/./b/../../c/";
//    cout<<solution.simplifyPath(path)<<endl;
    string path2 = "/home";
    cout<<solution.simplifyPath(path2)<<endl;
    return 0;
}


/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"
*/
