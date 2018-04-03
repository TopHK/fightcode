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
    int findPoisonedDuration_v1(vector<int>& timeSeries, int duration)
    {
        if(duration == 0) return 0;
        int size = timeSeries.size();
        if(size == 1) return duration;
        int currentPoisoneTime = 0;
        int sumPoisoneTime = 0;
        for(int i = 0; i < size; ++i)
        {
            if(i == 0 || currentPoisoneTime <= timeSeries[i])
            {
                currentPoisoneTime = timeSeries[i] + duration;
                sumPoisoneTime += duration;
            }
            else if(currentPoisoneTime <= timeSeries[i] + duration)
            {
                sumPoisoneTime += (timeSeries[i] + duration - currentPoisoneTime); 
                currentPoisoneTime = timeSeries[i] + duration;
            }
        }
        return sumPoisoneTime;
    }
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        if(duration == 0 || timeSeries.empty()) return 0;
        int size = timeSeries.size();
        if(size == 1) return duration;
        int sumPoisoneTime = 0;
        for(int i = 0; i < size-1; ++i)
        {
            sumPoisoneTime += min(timeSeries[i+1] - timeSeries[i], duration);
        }
        sumPoisoneTime += duration;
        return sumPoisoneTime;
    }
};

int main()
{
    Solution solution;
//    vector<int> timeSeries = {1,4};
    vector<int> timeSeries = {1,2};
    int duration = 2;
    cout<<solution.findPoisonedDuration(timeSeries, duration)<<endl;
    return 0;
}

