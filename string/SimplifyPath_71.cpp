#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string simplifyPath(string path)
    {
        string result;
        stringstream inputStream(path);
        vector<string> cache;

        string temp;
        while(getline(inputStream, temp, '/'))
        {
            if(temp == "." || temp == "") continue;
            else if(temp == "..")
            {
                if(!cache.empty()) cache.pop_back();
            }
            else
            {
                cache.push_back(temp);
            }
        }

        if(cache.empty()) return "/";
        for(int i = 0; i < cache.size(); ++i)
        {
            result += ('/' + cache[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
//    string path = "/a/./b/../../c/";
//    cout<<solution.simplifyPath(path)<<endl;
    string path2 = "/home";
    cout<<solution.simplifyPath(path2)<<endl;
    return 0;
}


/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
