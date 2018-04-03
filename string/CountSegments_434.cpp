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
    int countSegments(string s)
    {
        int count = 0;
        int size = s.size();
        for(int i = 0; i < size; ++i)
        {
            if(isspace(s[i])) continue;
            if(!isspace(s[i]))
            {
                count++;
                while(i < size && !isspace(s[i])) i++;
            }
        }
        return count;
    }
};


int main()
{
    Solution solution;
    string s = "Hello, my name is John";
    cout<<solution.countSegments(s)<<endl;
    return 0;
}


/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/
