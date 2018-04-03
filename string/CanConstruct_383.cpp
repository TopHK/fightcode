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
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mzMap;
        for(int i = 0; i < magazine.size(); ++i)
            mzMap[magazine[i]]++;
        for(int j = 0; j < ransomNote.size(); ++j)
        {
            if(mzMap.count(ransomNote[j]) == 0)
                return false;
            if(--mzMap[ransomNote[j]] == 0) mzMap.erase(ransomNote[j]);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s1 = "aa";
    string s2 = "aab";
    if(solution.canConstruct(s1, s2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
