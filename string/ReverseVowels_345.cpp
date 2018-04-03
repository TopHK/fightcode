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
    string reverseVowels_v1(string s)
    {
        int begin = 0;
        int end = s.size()-1;
        string vowels = "aeiouAEIOU";
        while(begin < end)
        {
            if(vowels.find(s[begin]) == string::npos)
            {
                begin++;
                continue;
            }
            if(vowels.find(s[end]) == string::npos)
            {
                end--;
                continue;
            }
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return s;
    }

    string reverseVowels(string s)
    {
        int begin = 0;
        int end = s.size()-1;
        string vowels = "aeiouAEIOU";
        while(begin < end)
        {
            begin = s.find_first_of(vowels, begin);
            end = s.find_last_of(vowels, end);
            if(begin < end) swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string s = "leetcode";
    string s2 = "hello";
    cout<<solution.reverseVowels(s)<<endl;
    cout<<solution.reverseVowels(s2)<<endl;
    return 0;
}


/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
