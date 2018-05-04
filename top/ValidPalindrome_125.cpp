/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

bool isPalindrome(string s)
{
    int left = 0;
    int right = s.size()-1;
    while(left < right)
    {
        while(left < right && !isalnum(s[left])) ++left;
        while(left < right && !isalnum(s[right])) --right;
        if(left < right)
        {
            if(tolower(s[left++]) != tolower(s[right--])) return false;
        }
    }
    return true;
}
