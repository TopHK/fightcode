#include<iostream>
#include<string>
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
    bool detectCapitalUse(string word)
    {
        int size = word.size();
        if(size == 0) return false;

        bool useCapital = (word[0] <= 90); // 首字母是否是大写
        int upperCount = 0;
        for(int i = 1; i < word.size(); ++i)
        {
            if(word[i] <= 90)
                upperCount++;
        }
        if(useCapital && (upperCount == size-1 || upperCount == 0)) return true;
        if(!useCapital && upperCount == 0) return true;
        return false;
    }
};

int main()
{
    Solution solution;
    string a = "USA";
    string b = "FlaG";
    string c = "leetcode";
    if(solution.detectCapitalUse(a)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(solution.detectCapitalUse(b)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(solution.detectCapitalUse(c)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/
