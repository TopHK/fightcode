#include<iostream>
#include<string>
#include<unordered_map>
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
    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix;
        int strSize = strs.size();
        if(strSize == 0) return prefix;
        if(strSize == 1) return strs[0];

        // step 1: find str that has the smallest length
        string miniStr = strs[0];
        for(int i = 1; i < strSize; ++i)
        {
            if(strs[i].size() < miniStr.size()) miniStr = strs[i];
        }

        // step 2: iterate miniStr
        bool hit = true;
        for(int i = 0, j = 0; i < miniStr.size(); ++i)
        {
            hit = true;
            for(j = 0; j < strSize; ++j)
            {
                if(strs[j][i] != miniStr[i])
                {
                    cout<<strs[j][i]<<endl;
                    hit = false;
                    break;
                }
            }
            if(hit) prefix += miniStr[i];
            else break;
        }
        return prefix;
    }
};


int main()
{
    Solution solution;
    vector<string> strs = {
        "aca", "cab"
    };
    cout<<solution.longestCommonPrefix(strs)<<endl;
    return 0;
}


/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
