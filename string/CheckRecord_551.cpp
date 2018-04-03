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
    bool checkRecord(string s)
    {
        int aCount = 0;
        int lCount = 0;
        int curLCount = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != 'L')
            {
                if(s[i] == 'A') aCount++;
                lCount = max(lCount, curLCount);
                curLCount = 0;
            }
            else curLCount++;
            lCount = max(lCount, curLCount);
            if(lCount > 2) return false;
        }
        return aCount <= 1;
    }
};

int main()
{
    Solution solution;
    string s = "LPALLP";
    string s2 = "PPALLLP";
    if(solution.checkRecord(s2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/
