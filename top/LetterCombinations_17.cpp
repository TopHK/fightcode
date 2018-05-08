vector<string> letterCombinations(string digits)
{
    const vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;

    if(digits.empty() || digits == "1") return result;
    result.push_back("");
    for(const auto& digit : digits)
    {
        string candidates = dict[digit-'0'];
        if(candidates.empty()) continue;

        vector<string> temp;
        for(const auto& candidate : candidates)
        {
            for(auto& re : result)
            {
                temp.push_back(re + candidate);
            }
        }
        result.swap(temp);
    }
    return result;
}
