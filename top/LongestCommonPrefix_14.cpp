/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

string commonPrefix(vector<string>& strs)
{
    string result;
    if(strs.empty()) return result;

    for(int i = 0; i < strs[0].size(); ++i)
    {
        char curCh = strs[0][i];
        bool same = true;
        for(int j = 1; j < strs.size(); ++j)
        {
            if(i >= strs[j].size() || strs[j][i] != curCh)
            {
                same = false;
                break;
            }
        }
        if(same) result += curCh;
        else break;
    }
    return result;
}
