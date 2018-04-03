#include<iostream>
#include<string>
#include <ctype.h>
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
    int compress_old(vector<char>& chars)
    {
        vector<int> chMap(256, 0);
        int size = chars.size();
        for(int i = 0; i < size; ++i) chMap[chars[i]]++;
        int totalLen = 0;
        for(int i = 0; i < size; ++i)
        {
            int curLen = chMap[chars[i]];
            if(curLen >= 1)
            {
                chMap[chars[i]] = 0;
                chars[totalLen++] = chars[i];
                if(curLen == 1) continue;
                string curLenStr = to_string(curLen);
                for(int j = 0; j < curLenStr.size(); ++j) chars[totalLen+j] = curLenStr[j];
                totalLen += curLenStr.size();
            }
        }
        return totalLen;
    }

    int compress(vector<char>& chars)
    {
        int size = chars.size();
        if(size == 0) return 0;

        int totalLen = 0;
        for(int i = 0; i < size; ++i)
        {
            chars[totalLen] = chars[i];
            totalLen++;
            int curLen = 1;
            while(i+1 < size && chars[i] == chars[i+1])
            {
                curLen++;
                i++;
            }
            if(curLen > 1)
            {
                string curLenStr = to_string(curLen);
                for(int j = 0; j < curLenStr.size(); ++j)
                    chars[totalLen++] = curLenStr[j];
            }
        }
        return totalLen;
    }
};

void printVector(const vector<char> chars)
{
    for(int i = 0; i < chars.size(); ++i) cout<<chars[i];
    cout<<endl;
}

int main()
{
    Solution solution;
    vector<char> chars = {'a','a','a','b','b','a','a'};
//    vector<char> chars = {'a'};
    cout<<solution.compress(chars)<<endl;
    printVector(chars);
    return 0;
}


/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/
