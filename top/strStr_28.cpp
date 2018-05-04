/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


*/

vector<int> generateNext(string needle)
{
    int k = -1;
    vector<int> next(neddle.size(), -1);
    for(int i = 1; i < needle.size(); ++i)
    {
        while(k > -1 && needle[i] != needle[k+1]) k = next[k];
        if(needle[i] == needle[k+1]) ++k;
        next[i] = k;
    }
    return next;
}

int strStr(string hayStack,string needle)
{
    if(needle.empty()) return 0;
    if(hayStack.empty()) return -1;

    vector<int> next = generateNext(needle);
    int k = -1;
    for(int i = 0; i < hayStack.size(); ++i)
    {
        while(k > -1 && hayStack[i] != needle[k+1]) k = next[k];
        if(hayStack[i] == needle[k+1]) ++k;
        if(k == needle.size()-1) return i-k;
    }
    return -1;
}
