#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
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
    int leastInterval_v1(vector<char>& tasks, int n)
    {
        int size = tasks.size();
        map<char, int> frequency;
        // step1: 统计每个任务的频数
        for(int i = 0; i < size; ++i) frequency[tasks[i]]++;

        // step2: 将每个任务的个数从小到大排序
        multiset<int, greater<int>> taskList;
        for(map<char, int>::iterator it = frequency.begin(); it != frequency.end(); ++it)
            taskList.insert(it->second);

        // step3: 每次执行n+1个interval，同时减去被执行任务的频数
        int minIntervals = 0;
        while(taskList.size())
        {
            int loopSize = 0;
            multiset<int, greater<int> > taskListCopy; // 新的multiset
            for(multiset<int, greater<int> >::iterator it = taskList.begin(); it != taskList.end(); ++it)
            {
                loopSize++;
                if(loopSize <= n+1)
                {
                    int nextValue = (*it)-1;
                    if(nextValue != 0) taskListCopy.insert(nextValue);
                }
                else taskListCopy.insert(*it);
            }
            if(taskListCopy.empty()) minIntervals += loopSize; // 最后一次连续执行完剩余的tasks，只加上执行tasks的个数
            else minIntervals += n+1; // 如果还有任务没有执行，那么需加上n+1
            taskList = taskListCopy;
        }
        return minIntervals;
    }

    int leastInterval(vector<char>& tasks, int n)
    {
        int size = tasks.size();
        vector<int> taskList(26, 0);
        for(int i = 0; i < size; ++i) taskList[tasks[i]-'A']++;
        sort(taskList.begin(), taskList.end());

        int m = 0;
        for(int j = 25; j >=0; --j)
        {
            if(taskList[j] == taskList[25]) m++;
            else break;
        }

        int minIntervals = (taskList[25]-1) * (n+1) + m;
        minIntervals = max(size, minIntervals);
        return minIntervals;
    }
};


int main()
{
    Solution solution;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout<<solution.leastInterval(tasks, n)<<endl;
    return 0;
}


/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.
Tasks could be done without original order. Each task could be done in one interval.
For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

Solution
If you have n identical tasks and need to separate by k steps, it needs (k+1)*(n-1) + 1 steps.
If you have m tasks all appear n times, it would take (k+1)*(n-1) + m when m <= k. All other tasks should be able to fill in the empty steps.

If all empty steps are filled out, then we do not need empty steps, the overall cost would be the size of input tasks.

https://leetcode.com/problems/task-scheduler/discuss/104504/C++-8lines-O(n)
*/


