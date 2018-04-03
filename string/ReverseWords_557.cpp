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
    string reverseWords_v1(string s)
    {
        stack<char> cache;
        string result;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                while(!cache.empty())
                {
                    result += cache.top();
                    cache.pop();
                }
                result += ' ';
            }
            else cache.push(s[i]);
        }
        while(!cache.empty())
        {
            result += cache.top();
            cache.pop();
        }
        return result;
    }

    string reverseWords(string s)
    {
        string result;
        string currentStr;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                if(!currentStr.empty())
                {
                    reverse(currentStr.begin(), currentStr.end());
                    result += currentStr;
                    currentStr.clear();
                }
                result += ' ';
            }
            else currentStr.push_back(s[i]);
        }
        if(!currentStr.empty())
        {
            reverse(currentStr.begin(), currentStr.end());
            result += currentStr;
            currentStr.clear();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string str = "Let's take LeetCode contest";
    cout<<solution.reverseWords(str)<<endl;
    return 0;
}


/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
