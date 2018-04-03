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
    bool isValid(string s)
    {
        unordered_map<char, char> brackets = {
            {')','('}, {'}','{'}, {']','['}
        };
        stack<char> cache;
        for(int i = 0; i < s.size(); ++i)
        {
            if(brackets.count(s[i]) == 0) cache.push(s[i]);
            else
            {
                if(cache.empty() || cache.top() != brackets[s[i]]) return false;
                cache.pop();
            }
        }
        return cache.empty();
    }
};

int main()
{
    Solution solution;
    string s = "()[]{}";
    string s2 = "([)]";
    if(solution.isValid(s2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
