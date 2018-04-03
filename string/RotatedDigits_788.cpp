#include<iostream>
#include<string>
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
    bool isGoodNum(string num)
    {
        int count018 = 0;
        int size = num.size();
        for(int i = 0; i < size; ++i)
        {
            if(num[i] == '3' || num[i] == '4' || num[i] == '7')
                return false;
            if(num[i] == '1' || num[i] == '8' || num[i] == '0')
                count018++;
        }
        return size != count018;
    }

    void rotatedDigitsCore(const string &N, string &s, int &count)
    {
        if(s.size() == N.size())
        {
            if(s <= N && isGoodNum(s)) count++;
            return;
        }
        if(s > N) return;

        string rotated = "0125689";
        for(int i = 0; i < rotated.size(); ++i)
        {
            s.push_back(rotated[i]);
            rotatedDigitsCore(N, s, count);
            s.pop_back();
        }
    }

    int rotatedDigits(int N)
    {
        int count = 0;
        string N2 = to_string(N);
        string s;
        rotatedDigitsCore(N2, s, count);
        return count;
    }
};

int main()
{
    Solution solution;
    int N = 20;
    cout<<solution.rotatedDigits(N)<<endl;
    return 0;
}


/*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.
Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other;
6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation:
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Note:

N  will be in range [1, 10000].
*/
