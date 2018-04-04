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
    int repeatedStringMatch_v1(string A, string B)
    {
        int count = 0;
        string As = A;
        for(int i = 1; i <= B.size()/A.size() + 2; ++i)
        {
            if(As.find(B) != string::npos) return i;
            As += A;
        }
        return -1;
    }

    int repeatedStringMatch(string A, string B)
    {
        int count = 0;
        int sizeA = A.size();
        int sizeB = B.size();
        for(int i = 0,j = 0; i < sizeA; ++i)
        {
            for(j = 0; j < sizeB; ++j)
            {
                if(A[(i + j) % sizeA] != B[j]) break;
            }
            if(j == sizeB) return (i + j) / sizeA + ((i+j) % sizeA == 0 ? 0 : 1);
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string A = "abcd";
    string B = "cdabcdab";
    cout<<solution.repeatedStringMatch(A, B)<<endl;
    return 0;
}


/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (¡°abcdabcdabcd¡±), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/
