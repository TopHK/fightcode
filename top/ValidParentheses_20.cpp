/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

bool validBrackets(string brackets)
{
    stack<char> st;
    unordered_map<char,char> dict({{')','('},{'}','{'},{']','['}});
    for(const auto& bracket : brackets)
    {
        if(dict.count(bracket) == 0) st.push(braket);
        else
        {
            if(st.empty() || st.top() != dict[bracket]) return false;
            st.pop();
        }
    }
    return st.empty();
}
