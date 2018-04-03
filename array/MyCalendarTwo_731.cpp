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

class MyCalendarTwo
{
private:
    map<int, int> originalMap; // 原[start, end]区间
    map<int, int> overlapMap;  // 交叉区间的map
public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        map<int, int>::iterator itStart = overlapMap.upper_bound(start);
        // 第二次交叉
        if(itStart != overlapMap.end() && itStart->second < end)
            return false;

        itStart = originalMap.upper_bound(start);
        // 与原区间有交叉
        if(itStart != originalMap.end() && itStart->second < end)
        {
            while(itStart != originalMap.end())
            {
                int curStart = itStart->second;
                int curEnd = itStart->first;
                if(max(curStart, start) < min(curEnd, end))
                {
                    overlapMap[min(curEnd, end)] = max(curStart, start);
                }
                else break;
                itStart++;
            }
        }
        originalMap[end] = start;
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */


int main()
{
    MyCalendarTwo calendar;
    int start1 = 10, end1 = 20;
    if(calendar.book(start1, end1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start2 = 50, end2 = 60;
    if(calendar.book(start2, end2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start3 = 10, end3 = 40;
    if(calendar.book(start3, end3)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start4 = 5, end4 = 15;
    if(calendar.book(start4, end4)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start5 = 5, end5 = 10;
    if(calendar.book(start5, end5)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    int start6 = 25, end6 = 55;
    if(calendar.book(start6, end6)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


/*
Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation:
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/


