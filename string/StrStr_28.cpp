#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
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
    vector<int> generateNext(const string &needle)
    {
        int k = -1;
        int size = needle.size();
        vector<int> next(size, -1);

        for(int i = 1; i < size; ++i)
        {
            while(k > -1 && needle[k + 1] != needle[i]) k = next[k];
            if(needle[k + 1] == needle[i]) k++;
            next[i] = k;
        }
        return next;
    }

    int strStr(string haystack, string needle)
    {
        if(needle.empty()) return 0;
        vector<int> next = generateNext(needle);
        int k = -1;
        for(int i = 0; i < haystack.size(); ++i)
        {
            while(k > -1 && needle[k + 1] != haystack[i]) k = next[k];
            if(needle[k + 1] == haystack[i]) k++;
            if(k == needle.size()-1) return i - k;
        }
        return -1;
    }
};


int main()
{
    Solution solution;
    string haystack = "hello";
    string needle = "ll";
    cout<<solution.strStr(haystack, needle)<<endl;
    return 0;
}


/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/
