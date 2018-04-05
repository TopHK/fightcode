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
    vector<int> parseComplex(string str)
    {
        int iPos = str.find('+');
        vector<int> result;
        result.push_back(stoi(str.substr(0, iPos)));
        result.push_back(stoi(str.substr(iPos+1, str.size()-iPos-2)));
        return result;
    }

    string complexNumberMultiply(string a, string b)
    {
        vector<int> aVector = parseComplex(a);
        vector<int> bVector = parseComplex(b);
        int realNum = (aVector[0] * bVector[0] - aVector[1] * bVector[1]);
        int imageNum = (aVector[0] * bVector[1] + aVector[1] * bVector[0]);
        string result = to_string(realNum) + '+' + to_string(imageNum) + 'i';
        return result;
    }
};

int main()
{
    Solution solution;
    string a = "1+-1i";
    string b = "1+-1i";
    cout<<solution.complexNumberMultiply(a, b)<<endl;
    return 0;
}


/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/
