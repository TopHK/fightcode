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
    int romanToInt(string s)
    {
        unordered_map<char, int> romanMap(
                                          {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}
                                          );
        int result = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(romanMap[s[i-1]] < romanMap[s[i]]) result -= romanMap[s[i-1]];
            else result += romanMap[s[i-1]];
        }
        if(!s.empty()) result += romanMap[s.back()];
        return result;
    }
};

int main()
{
    Solution solution;
    string s("DCXXI");
    cout<<solution.romanToInt(s)<<endl;
    return 0;
}


/*

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
