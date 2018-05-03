/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findUnique(string s)
{
    vector<int> dict(26,0);
    for(const auto& c : s)
    {
        dict[c-'a']++;
    }
    for(int i = 0; i < s.size(); ++i)
    {
        if(dict[s[i]-'a'] == 1) return i;
    }
    return -1;
}

int main()
{
    string s("loveleetcode");
    cout<<findUnique(s)<<endl;
    return 0;
}
