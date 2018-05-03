/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.size() != t.size()) return false;
    unordered_map<char, int> dict;
    for(const auto& c : s) dict[c]++;

    for(const auto& c: t)
    {
        if(dict.count(c) == 0) return false;
        dict[c]--;
        if(dict[c] == 0) dict.erase(c);
    }
    return dict.empty();
}

int main()
{
    string s("rat");
    string t("car");
    if(isAnagram(s, t)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
