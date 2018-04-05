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
    string customSortString_v1(string S, string T)
    {
        vector<int> tFrequency(26, 0);
        string result;
        int tSize = T.size();
        int sSize = S.size();

        // count frequency of each letter in T
        for(int i = 0; i < tSize; ++i) tFrequency[T[i]-'a']++;

        // iterate S, append letters of S to result
        for(int j = 0; j < sSize; ++j)
        {
            int f = tFrequency[S[j]-'a'];
            if(f)
            {
                result += string(f, S[j]);
                tFrequency[S[j]-'a'] = 0;
            }
        }

        // append other letters which not exist in S to result
        for(int k = 0; k < 26; ++k)
        {
            int f = tFrequency[k];
            if(f) result += string(f, k + 'a');
        }
        return result;
    }

    string customSortString(string S, string T)
    {
        sort(T.begin(), T.end(),
             [&](char a, char b) { return S.find(a) < S.find(b); });
        return T;
    }
};

int main()
{
    Solution solution;
    string S = "cba";
    string T = "abcd";
    cout<<solution.customSortString(S, T)<<endl;
    return 0;
}


/*
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted.
More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input:
S = "cba"
T = "abcd"
Output: "cbad"
Explanation:
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.


Note:

S has length at most 26, and no character is repeated in S.
T has length at most 200.
S and T consist of lowercase letters only.
*/
