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
    bool repeatedSubstringPattern_v1(string s)
    {
        bool result = false;
        int size = s.size();
        for(int i = 1; i <= (size >> 1); ++i)
        {
            string temp = s.substr(i) + s.substr(0, i);
            if(temp == s) return true;
        }
        return result;
    }

    // KMP
    bool repeatedSubstringPattern(string s)
    {
        bool result = false;
        int size = s.size();
        vector<int> next(size, -1);
        int k = -1;
        for(int i = 1; i < size; ++i)
        {
            while(k > -1 && s[k+1] != s[i]) k = next[k];
            if(s[k+1] == s[i]) k++;
            next[i] = k;
        }
        int rightLen = next[size-1] + 1;
        return rightLen && (rightLen % (size-rightLen) == 0);
    }
};


int main()
{
    Solution solution;
    string s = "abcabcabcabc";
    string s2 = "abab";
    string s3 = "aba";
    if(solution.repeatedSubstringPattern(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(solution.repeatedSubstringPattern(s2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(solution.repeatedSubstringPattern(s3)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
