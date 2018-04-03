#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int findShortestSubArray_v1(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 1) return size;
        map<int, int> freq;
        for(int i = 0; i < size; ++i) freq[nums[i]]++;
        vector<int> maxFrequencyNum;
        int maxFrequency = 0;
        for(map<int,int>::iterator it=freq.begin(); it != freq.end(); ++it)
        {
            int currentNum = it->first;
            int currentFreq = it->second;
            if(currentFreq > maxFrequency)
            {
                maxFrequencyNum.clear();
                maxFrequencyNum.push_back(currentNum);
                maxFrequency = currentFreq;
            }
            else if(currentFreq == maxFrequency)
                maxFrequencyNum.push_back(currentNum);               
        }
        int minLength = size;
        for(int pos = 0; pos < maxFrequencyNum.size(); ++pos)
        {
            int currentValue = maxFrequencyNum[pos];
            int start = 0;
            for(int i = 0; i < size; ++i)
            {
                if(nums[i] == currentValue)
                {
                    start = i;
                    break;
                }
            }
            int end = size-1;
            for(int j = size-1; j >= 0; --j)
            {
                if(nums[j] == currentValue)
                {
                    end = j;
                    break;
                }
            }
            if(end-start+1 < minLength) minLength = end-start+1;
        }
        return minLength; 
    }
    int findShortestSubArray(vector<int>& nums) {
        
        int frequency = 1;
        int length = 1;
        map<int, pair<int, int>> count;
        
        for(int i = 0; i < nums.size(); i++)
        {
            map<int, pair<int, int>>::iterator it = count.find(nums[i]);
            if(it == count.end())
                count[nums[i]] = make_pair(1, i);
            else
            {
                int n = ++(it->second).first;
                if(n > frequency)
                {
                    frequency = n;
                    length = i-(it->second).second+1;
                }
                else if(n == frequency)
                {
                    int l = i-(it->second).second+1;
                    if(l < length) length = l;
                }
            }
        }
        
        return length;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 4, 4, 2};
    cout<<solution.findShortestSubArray(nums)<<endl;
    return 0;
}

