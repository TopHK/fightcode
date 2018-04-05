#include<iostream>
#include<string>
#include <ctype.h>
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
    void addParenthesis(vector<string> &result, string str, int leftCount, int rightCount)
    {
        if(leftCount == 0 && rightCount == 0)
        {
            result.push_back(str);
            return;
        }
        if(leftCount > 0) addParenthesis(result, str+'(', leftCount-1, rightCount);
        if(rightCount > leftCount) addParenthesis(result, str+')', leftCount, rightCount-1);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string str;
        addParenthesis(result, str, n, n);
        return result;
    }
};

void print(const vector<string> &result)
{
    for(int i = 0; i < result.size(); ++i) cout<<result[i]<<endl;
    cout<<endl;
}

int main()
{
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);
    print(result);
    return 0;
}


/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
