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
    string reverseStr(string s, int k)
    {
        string result;
        for(int i = 0; i < s.size(); i = i+2*k)
        {
            int start = i;
            int len = (start+k < s.size() ? k : s.size()-start);
            string temp = s.substr(start, len);
            reverse(temp.begin(), temp.end());
            result += temp;

            if(start+len < s.size())
            {
                start = start+len;
                len = (start+k < s.size() ? k : s.size()-start);
                temp = s.substr(start, len);
                result += temp;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "abcdefg";
    int k = 2;
    cout<<solution.reverseStr(s, k)<<endl;
    return 0;
}


/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string.
If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/
