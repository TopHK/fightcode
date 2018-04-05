#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> DP(size1+1, vector<int>(size2+1, 0));

        for(int i = 0; i <= size1; ++i)
        {
            for(int j = 0; j <= size2; ++j)
            {
                if(i == 0) DP[0][j] = j;
                else if(j == 0) DP[i][0] = i;
                else if(word1[i-1] == word2[j-1]) DP[i][j] = DP[i-1][j-1];
                else DP[i][j] = min(DP[i][j-1] + 1, DP[i-1][j] + 1);
            }
        }
        return DP[size1][size2];
    }
};

int main()
{
    Solution solution;
    string word1 = "sea";
    string word2 = "eat";
    cout<<solution.minDistance(word1, word2)<<endl;
    return 0;
}


/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/
