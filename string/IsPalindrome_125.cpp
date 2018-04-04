#include<iostream>
#include<string>
#include<ctype.h>
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
    bool isPalindrome(string s)
    {
        bool valid = true;
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            while(left < right && !isalnum(s[left])) left++;
            while(right > left && !isalnum(s[right])) right--;
            if(left < right)
            {
                if(tolower(s[left++]) != tolower(s[right--]))
                {
                    valid = false;
                    break;
                }
            }
        }
        return valid;
    }
};

int main()
{
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    if(solution.isPalindrome(s)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    string s2 = "race a car";
    if(solution.isPalindrome(s2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
