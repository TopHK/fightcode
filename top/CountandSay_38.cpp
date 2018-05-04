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

#include<iostream>
#include<string>
using namespace std;

string generateNext(string term)
{
    term.push_back('#');
    string result;
    int curCount = 1;
    char curCh = term[0];
    for(int i = 1; i < term.size(); ++i)
    {
        char t = term[i];
        if(t == curCh) ++curCount;
        else
        {
            result += (to_string(curCount) + curCh);
            curCh = t;
            curCount = 1;
        }
    }
    return result;
}

string countSay(int n)
{
    string term("1");
    int id = 1;
    while(id < n)
    {
        term = generateNext(term);
        ++id;
    }
    return term;
}

int main()
{
    int n = 4;
    cout<<countSay(n)<<endl;
    return 0;
}
