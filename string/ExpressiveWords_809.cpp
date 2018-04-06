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
    // »¬¶¯´°¿ÚËã·¨
    int expressiveWords(string S, vector<string>& words)
    {
        int res = 0;
        for (auto &w : words)
        {
            if (w.size() <= S.size())
            {
                int i, j;
                for (i = 0, j = 0; j < S.size(); j++)
                {
                    if (i <= w.size() && w[i] == S[j]) // w[i] references to a null char when i reaches w.size()
                        i++;
                    else if (j > 0 && S[j] == S[j - 1] && j + 1 < S.size() && S[j] == S[j + 1]) // last, this and next
                        j++;
                    else if (!(j > 1 && S[j] == S[j - 1] && S[j] == S[j - 2])) // this and last 2 chars
                        break;
                }
                if (i == w.size() && j == S.size()) // both pointers reach the end
                    res++;
            }
        }
        return res;
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
    string S = "heeellooo";
    vector<string> words = {"hello", "hi", "helo"};
    cout<<solution.expressiveWords(S, words)<<endl;
    return 0;
}


/*
Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy.

Example:
Input:
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation:
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters
*/
