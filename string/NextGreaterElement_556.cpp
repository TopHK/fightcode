#include<iostream>
#include<string>
#include<limits.h>
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
    int nextGreaterElement(int n)
    {
        long long result = -1;
        string str = to_string(n);
        int size = str.size();

        // step 1: find the descending consecutive sequence in the tail of string
        // range: [pos, size)
        int pos = size-2;
        while(pos >= 0 && str[pos] >= str[pos+1]) pos--;
        if(pos < 0) return -1;

        // step 2: sort the found sub string
        pos++;
        sort(str.begin() + pos, str.end());

        // step 3: find the swap pos
        int leftPos = pos-1;
        while(pos < size && str[leftPos] >= str[pos]) pos++;
        swap(str[leftPos], str[pos]);
        result = stol(str);
        return result > INT_MAX ? -1 : int(result);
    }
};

int main()
{
    Solution solution;
    int n = 13;
    cout<<solution.nextGreaterElement(n)<<endl;
    return 0;
}


/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:

Input: 12
Output: 21


Example 2:

Input: 21
Output: -1
*/
