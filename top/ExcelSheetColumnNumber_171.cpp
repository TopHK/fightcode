/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/

#include<iostream>
#include<string>
using namespace std;

int getNum(string title)
{
    int num = 0;
    for(int i = 0; i < title.size(); ++i)
    {
        num *= 26;
        num += (title[i]-'A'+1);
    }
    return num;
}

int main()
{
    string title1("ZY");
    cout<<getNum(title1)<<endl;
    return 0;
}
