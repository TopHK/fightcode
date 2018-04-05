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
    string countAndSay(int n)
    {
        if(n <= 0) return "";
        string result = "1";

        for(int i = 2; i <= n; ++i)
        {
            string temp;
            int count = 0;
            char curCh;
            for(int j = 0; j < result.size(); ++j)
            {
                if(j == 0)
                {
                    curCh = result[0];
                    count = 1;
                }
                else
                {
                    if(result[j] == result[j-1]) count++;
                    else
                    {
                        temp += to_string(count);
                        temp += curCh;
                        curCh = result[j];
                        count = 1;
                    }
                }
                if(j == result.size()-1)
                {
                    temp += to_string(count);
                    temp += curCh;
                }
            }
            result = temp;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int n = 2;
    cout<<solution.countAndSay(n)<<endl;
    return 0;
}


/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
*/
