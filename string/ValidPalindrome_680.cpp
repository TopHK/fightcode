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
    bool validPalindrome_v1(string s)
    {
        int size = s.size();
        int i = 0, j = size-1;
        bool hasDelete = false;
        bool valid = true;
        // É¾³ýÓÒ±ßµÄ×Ö·û
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else if(!hasDelete)
            {
                if(j-1 >= i && s[i] == s[j-1]) j--;
                hasDelete = true;
            }
            else
            {
                valid = false;
                break;
            }
        }
        if(valid) return true;

        // É¾³ý×ó±ßµÄ×Ö·û
        hasDelete = false;
        valid = true;
        i = 0;
        j = size-1;
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else if(!hasDelete)
            {
                if(i+1 <= j && s[i+1] == s[j]) i++;
                hasDelete = true;
            }
            else
            {
                valid = false;
                break;
            }
        }
        return valid;
    }

    bool isPalindrome(const string &s, int begin, int end)
    {
        while(begin < end)
        {
            if(s[begin] != s[end]) return false;
            begin++;
            end--;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int size = s.size();
        int begin = 0;
        int end = size-1;
        while(begin < end)
        {
            if(s[begin] != s[end])
            {
                return isPalindrome(s, begin+1, end) || isPalindrome(s, begin, end-1);
            }
            begin++;
            end--;
        }
        return true;
    }
};


int main()
{
    Solution solution;
    string A = "abca";
    string B = "abcca";
    string C = "accba";
    string D = "ebcbbececabbacecbbcbe";
    string E = "ececabbacec";
    if(solution.validPalindrome(A)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(solution.validPalindrome(B)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(solution.validPalindrome(C)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(solution.validPalindrome(D)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/
