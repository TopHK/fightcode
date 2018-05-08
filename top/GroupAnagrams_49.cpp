/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> cache;
    for(const auto& str : strs)
    {
        string temp(str);
        sort(temp.begin(), temp.end());
        if(cache.count(temp) == 0)
        {
            cache[temp] = {str};
        }
        else cache[temp].push_back(str);
    }

    for(unordered_map<string,vector<string>>::iterator it = cache.begin(); it != cache.end(); ++it)
    {
        result.push_back(it->second);
    }
    return result;
}
