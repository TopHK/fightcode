#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    bool isValidSeries(const vector<int>& bits, int end)
    {
        if(end < 0) return true;
        if(end == 0) return (bits[0] == 0);
        else 
        {
            bool flag1 = false, flag2 = false;
            if(bits[end] == 0) flag1 = isValidSeries(bits, end-1);
            if((bits[end-1] == 1 && bits[end] == 0) || (bits[end-1] == 1 && bits[end] == 1))
               flag2 = isValidSeries(bits, end-2);
            return (flag1 || flag2);
        }
    }

    bool isOneBitCharacter(vector<int>& bits)
    {
        int size = bits.size();
        if(size == 0) return false;
        if(bits[size-1] == 0) return isValidSeries(bits, size-2); 
        return false; 
    }

};

int main()
{
    Solution solution;
//    vector<int> bits = {1, 1, 1, 0};
    vector<int> bits = {1, 0, 0};
    if(solution.isOneBitCharacter(bits)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

