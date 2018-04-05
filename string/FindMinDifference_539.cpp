#include<iostream>
#include<string>
#include<unordered_map>
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
    int to_min(string& a)
    {
        int h = (a[0]-'0')*10+(a[1]-'0'), m = (a[3]-'0')*10+(a[4]-'0');
        return 60*h+m;
    }
    int findMinDifference(vector<string>& timePoints)
    {
        int n = timePoints.size();
        if (n > 1440) return 0;
        vector<int> times;
        for (int i = 0; i < n; i++)
            times.push_back(to_min(timePoints[i]));
        sort(times.begin(), times.end());
        int ans = times[0]+60*24-times.back();
        for (int i = 1; i < n; ++i) {
            ans = min(ans, times[i]-times[i-1]);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> timePoints = {"23:59","00:00"};
    cout<<solution.findMinDifference(timePoints)<<endl;
    return 0;
}


/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/
