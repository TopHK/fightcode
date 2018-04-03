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

class Solution
{
public:
    int countBinarySubstrings_v1(string s)
    {
        int count = 0;
        int len = 1;
        while(true)
        {
            bool found = false;
            string str1 = string(len , '1') + string(len, '0');
            int pos = 0;
            while(true)
            {
                pos = (int)s.find(str1, pos);
                if(pos != string::npos)
                {
                    pos++;
                    count++;
                    found = true;
                }
                else break;
            }
            string str2 = string(len , '0') + string(len, '1');
            pos = 0;
            while(true)
            {
                pos = (int)s.find(str2, pos);
                if(pos != string::npos)
                {
                    pos++;
                    count++;
                    found = true;
                }
                else break;
            }
            if(!found) break;
            len++;
        }
        return count;
    }
    int countBinarySubstrings_v2(string s)
    {
        int count = 0;
        int size = s.size();
        vector<int> frequency(size, 0); // 以第i个为尾字符的连续子序列的长度，00或者11
        for(int i = 0; i < size; ++i)
        {
            if(i != 0 && s[i] == s[i-1])
                frequency[i] = (s[i] == '0' ? frequency[i-1]+1 : frequency[i-1]-1);
            else frequency[i] = (s[i] == '0' ? 1 : -1);

            int previousPos = i - abs(frequency[i]);
            if(previousPos < 0) continue;
            if(abs(frequency[previousPos]) >= abs(frequency[i]))
                count++;
        }
        return count;
    }
    int countBinarySubstrings_v3(string s)
    {
        int size = s.size();
        vector<int> frequency;
        int count = 1;
        for(int i = 1; i < size; ++i)
        {
            if(s[i] != s[i-1])
            {
                frequency.push_back(count);
                count = 1;
            }
            else count++;
        }
        frequency.push_back(count);

        int totalCount = 0;
        for(int j = 1; j < frequency.size(); ++j)
            totalCount += min(frequency[j], frequency[j-1]);
        return totalCount;
    }

    int countBinarySubstrings(string s)
    {
        int count = 0;
        int size = s.size();
        int curCount = 1;
        int preCount = 0;
        for(int i = 1; i < size; ++i)
        {
            if(s[i] == s[i-1]) curCount++;
            else
            {
                preCount = curCount;
                curCount = 1;
            }
            if(preCount >= curCount) count++;
        }
        return count;
    }
};

int main()
{
    Solution solution;
    string s = "00110011";
    string s2 = "10101";
    cout<<solution.countBinarySubstrings(s)<<endl;
    cout<<solution.countBinarySubstrings(s2)<<endl;
    return 0;
}


/*
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's,
and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
*/
