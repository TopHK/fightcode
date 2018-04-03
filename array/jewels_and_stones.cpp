#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

class Solution
{
public:
    int numJewelsInStones_v1(string J, string S) 
    {
        if(J.empty() || S.empty()) return 0;
        int num = 0;
        for(int i = 0; i < S.length(); ++i)
        {
            if(J.find(S[i]) != string::npos)
                num++;
        }
        return num;
    }
    int numJewelsInStones_v2(string J, string S) 
    {
        set<char> J_set(J.begin(), J.end());
        int num = 0;
        for(char s : S)
        {
            if(J_set.count(s) != 0) num++;
        }
        return num;
    }
    int numJewelsInStones_v3(string J, string S) 
    {
	bool J_set[123]; // 65-90; 97-122; 48-57	
       	memset(J_set + 65, false, 58);
	for(char j : J) J_set[j] = true;
        int num = 0;
        for(char s : S)
        {
            if(J_set[s]) num++;
        }
        return num;
    }
    int numJewelsInStones_v4(string J, string S) 
    {
	sort(S.begin(), S.end());	
        int num = 0;
        for(char j : J)
        {
            num += (upper_bound(S.begin(), S.end(), j) - lower_bound(S.begin(), S.end(), j)); 
        }
        return num;
    }

};

int main()
{
    Solution solution;
    string J = "aA";
    string S = "aAAbbbb";
//    string J = "z";
//    string S = "ZZ";
    cout<<solution.numJewelsInStones_v4(J, S)<<endl;
    return 0;
}

