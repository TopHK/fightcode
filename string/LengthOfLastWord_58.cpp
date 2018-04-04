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
    int lengthOfLastWord(string s)
    {
        int length = 0;
        bool isWord = false;
        for(int i = s.size()-1; i >=0; i--)
        {
            if(s[i] == ' ')
            {
                if(isWord) break;
            }
            else
            {
                length++;
                isWord = true;
            }
        }
        return length;
    }
};


int main()
{
    Solution solution;
    string s = "Hello World";
    cout<<solution.lengthOfLastWord(s)<<endl;
    return 0;
}


/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
