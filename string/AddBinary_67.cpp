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
    string addBinary(string a, string b)
    {
        int carry = 0;
        int sizeA = a.size();
        int sizeB = b.size();
        string result = string(max(sizeA, sizeB)+1, '0');

        int i = sizeA-1;
        int j = sizeB-1;
        int pos = result.size() - 1;
        while(i >= 0 || j >= 0 || carry == 1)
        {
            int digit = carry;
            if(i >= 0) digit += (a[i--] - '0');
            if(j >= 0) digit += (b[j--] - '0');
            carry = digit / 2;
            digit %= 2;
            result[pos--] = (digit + '0');
        }
        return (pos == 0 ? result.substr(1) : result);
    }
};

int main()
{
    Solution solution;
    string a = "11";
    string b = "1";
    cout<<solution.addBinary(a, b)<<endl;
    return 0;
}


/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
