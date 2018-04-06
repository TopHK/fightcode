#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

bool cmp(pair<string,int> &a, pair<string,int> &b)
{
    return a.first.size() > b.first.size();
}

bool isS1subsOfS2(string &s1, string &s2)
{
    int i = 0, j = 0;
    while(i < s1.size() && j < s2.size())
    {
        if(s1[i] == s2[j]) i++;
        j++;
    }
    return i == s1.size();
}

class Solution {
public:
    int findLUSlength(vector<string>& strs)
    {
        unordered_map<string,int> m;
        for(int i = 0; i < strs.size(); ++i)
          ++m[strs[i]];
        vector<pair<string,int>> v;
        for(auto it = m.begin(); it != m.end(); ++it)
           v.push_back(*it);
        sort(v.begin(),v.end(),cmp);
        for(int i = 0; i < v.size(); ++i)
        {
           if(v[i].second == 1){
               int j = 0;
               for(; j < i; ++j)
                 if(isS1subsOfS2(v[i].first,v[j].first))
                     break;
               if(j == i) return v[i].first.size();
           }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string a = "aba";
    string b = "cdc";
    cout<<solution.findLUSlength(a, b)<<endl;
    return 0;
}


/*
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
*/
