#include<iostream>
#include<string>
#include<unordered_map>
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
    int firstUniqChar(string s)
    {
        vector<int> chVector(256, 0);
        for(int i = 0; i < s.size(); ++i) chVector[s[i]]++;
        for(int j = 0; j < s.size(); ++j)
        {
            if(chVector[s[j]] == 1) return j;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string s = "loveleetcode";
    cout<<solution.firstUniqChar(s)<<endl;
    return 0;
}


/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
