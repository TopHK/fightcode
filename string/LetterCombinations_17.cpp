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
    vector<string> letterCombinations(string digits)
    {
        const vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> results;
        if(digits.empty() || digits == "1") return results;
        results.push_back("");
        for(const auto& digit : digits)
        {
            string candidates = dict[digit-'0'];
            if(candidates.empty()) continue;

            vector<string> tempResults;
            for(const auto& candidate : candidates)
            {
                for(const auto& result : results)
                {
                    tempResults.push_back(result + candidate);
                }
            }
            results.swap(tempResults);
        }
        return results;
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
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
