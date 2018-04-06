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
    string reorganizeString_v1(string S)
    {
        vector<int> mp(26);
        int n = S.size();
        for (char c: S) ++mp[c-'a'];
        vector<pair<int, char>> charCounts;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) charCounts.push_back({mp[i], i+'a'});
        }
        sort(charCounts.rbegin(), charCounts.rend());
        string strSorted;
        for (auto& p: charCounts)
            strSorted += string(p.first, p.second);
        string ans;
        for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j)
        {
            ans += strSorted[i];
            if (j < n) ans += strSorted[j];
        }
        return ans;
    }

    string reorganizeString(string S)
    {
        if(S.size() <2) return S;
        int maxc = 1;
        int maxi = 0;
        vector<int> m(26,0);
        for( char c :S)
        {
             m[c-'a']++;
            if(m[c-'a']>maxc)
            {
                maxc = m[c-'a'];
                maxi = c-'a';
            }
        }
        if(maxc > (S.size()+1)/2)
            return "";
        int i =0;
        while(m[maxi]--)
        {
            S[i]= maxi +'a';
            i+=2;
        }
        for(int j =0;j< 26;j++)
        {
            while(m[j]-->0)
            {
                if(i>=S.size())
                {
                    i = 1;
                }
                S[i] = j+'a';
                i+=2;
            }
        }
        return S;
    }
};

void printVector2D(const vector<vector<string>> &result)
{
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}

void printVector(const vector<string> &result)
{
    for(int i = 0; i < result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;
}

int main()
{
    Solution solution;
    string digits = "23";
    vector<string> results = solution.letterCombinations(digits);
    printVector(results);
    return 0;
}


/*
Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].
*/
