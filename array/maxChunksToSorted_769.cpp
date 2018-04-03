#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void printVector(vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
public:
    int maxChunksToSorted_v1(vector<int>& arr)
    {
        int size = arr.size();
        int maxCount = 0;
        int maxIndex = -1;
        for(int i = 0; i < size; ++i)
        {
            cout<<maxIndex<<" "<<i<<" "<<maxCount<<endl;
            if(i > maxIndex)
            {
                maxCount++;
                maxIndex = i;
            }
            while(arr[i] != i)
            {
                int temp = arr[i];
                arr[i] = arr[temp];
                arr[temp] = temp;
                maxIndex = max(maxIndex, temp);
            }
        }
        return maxCount;
    }

    int maxChunksToSorted(vector<int>& arr)
    {
        int size = arr.size();
        int maxCount = 0;
        int maxNum = 0;
        for(int i = 0; i < size; ++i)
        {
            maxNum = max(maxNum, arr[i]);
            if(maxNum == i) maxCount++;
        }
        return maxCount;
    }
};


int main()
{
    Solution solution;
    //vector<int> nums = {4,3,2,1,0};
    //vector<int> nums = {1,0,2,3,4};
    vector<int> nums = {0,4,5,2,1,3};
    cout<<solution.maxChunksToSorted(nums)<<endl;
    return 0;
}


/*
Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.
After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 10].
arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
*/

