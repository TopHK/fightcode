#include<iostream>
#include<string>
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
    string reverseString(string s)
    {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s2;
    }
};

int main()
{
    Solution solution;
    string str = "abc";
    cout<<solution.reverseString(str)<<endl;
    return 0;
}


/*
Write a function that takes a string as input and returns the string reversed.
*/
