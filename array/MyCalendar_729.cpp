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

class MyCalendar_v1
{
private:
    map<int, int> indexMap;
public:
    MyCalendar()
    {
        indexMap[-1] = -1;
    }

    bool book(int start, int end)
    {
        if(indexMap.count(start) != 0) return false;
        bool result = false;
        int priEnd = INT_MIN;
        for(map<int, int>::iterator it = indexMap.begin(); it != indexMap.end(); ++it)
        {
            int currentStart = it->first;
            int currentEnd = it->second;
            // 上一单元的尾部index < 当前单元的开始index
            if(priEnd > currentStart) break;
            // [start, end)在[priEnd, currentStart]范围内
            if(start >= priEnd && end <= currentStart)
            {
                result = true;
                break;
            }
            priEnd = currentEnd;
        }
        if(start >= priEnd) result = true;
        if(result) indexMap[start] = end;
        return result;
    }
};

class MyCalendar
{
private:
    map<int, int> indexMap;
public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        map<int, int>::iterator it_start = indexMap.upper_bound(start);
        if(it_start == indexMap.end() || it_start->second >= end)
        {
            indexMap[end] = start;
            return true;
        }
        return false;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */


int main()
{
    MyCalendar calendar;
    int start1 = 10, end1 = 20;
    if(calendar.book(start1, end1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start2 = 15, end2 = 25;
    if(calendar.book(start2, end2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start3 = 20, end3 = 30;
    if(calendar.book(start3, end3)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start4 = 2, end4 = 8;
    if(calendar.book(start4, end4)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end),
the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking.
Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation:
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/


