#include<iostream>
#include<vector>
using namespace std;

//int x=[](){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    return 0;
//}();

class Solution
{
public:
    // check by modify original vector
    bool checkPossibility_v1(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 2) return true;

        int modified = 0;
        for(int i = 1; i < size; ++i)
        {
            if(nums[i-1] > nums[i])
            {
                if(i-2 < 0 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
                if(++modified > 1) return false;
            }
        }
        return true;
    }

    // check by modify original vector
    bool checkPossibility(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 2) return true;

        int modified = 0;
        int prevNum = nums[0];
        for(int i = 1; i < size; ++i)
        {
            if(prevNum > nums[i])
            {
                if(++modified > 1) return false;
                if(i-2 >= 0 && nums[i-2] > nums[i]) continue;
            }
            prevNum = nums[i];
        }
        return true;
    }
};

//int main()
//{
//    Solution solution;
//    vector<int> nums = {3,4,2,3};
//    if(solution.checkPossibility(nums))
//        cout<<"Yes"<<endl;
//    else cout<<"No"<<endl;
//    return 0;
//}


/*
²Î¿¼£ºhttps://leetcode.com/problems/non-decreasing-array/discuss/106849/C++-Java-Clean-Code-6-liner-Without-Modifying-Input
The strategy is to lower a[i-1] to match a[i] if possible - (a[i-2] not exist or no smaller than a[i]);
otherwise rise a[i] to match a[i-1].

2 Examples:
 0  ...  i ...
 1 1 2 4[2]5 6  - in this case we can just raise a[i] to 4;
         4
 1 1 2[4]2 3 4  - in this case lower a[i-1] is better;
       2
Java - Modifying Input

class Solution {
    public boolean checkPossibility(int[] a) {
        int modified = 0;
        for (int i = 1; i < a.length; i++) {
            if (a[i] < a[i - 1]) {
                if (modified++ > 0) return false;
                if (i - 2 < 0 || a[i - 2] <= a[i]) a[i - 1] = a[i]; // lower a[i - 1]
                else a[i] = a[i - 1]; // rise a[i]
            }
        }
        return true;
    }
}
We can also do it without modifying the input by using a variable prev to hold the a[i-1]; if we have to lower a[i] to match a[i-1] instead of raising a[i-1], simply skip updating prev;
Java - Without Modifying Input

class Solution {
    public boolean checkPossibility(int[] a) {
        int modified = 0;
        for (int i = 1, prev = a[0]; i < a.length; i++) {
            if (a[i] < prev) {
                if (modified++ > 0) return false;
                if (i - 2 >= 0 && a[i - 2] > a[i]) continue;
            }
            prev = a[i];
        }
        return true;
    }
}
Or

class Solution {
    public boolean checkPossibility(int[] a) {
        int modified = 0;
        for (int i = 1, prev = a[0]; i < a.length; i++) {
            if (a[i] < prev && modified++ > 0) return false;
            if (a[i] < prev && i - 2 >= 0 && a[i - 2] > a[i]) continue;
            prev = a[i];
        }
        return true;
    }
}
C++ - Modifying Input

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        bool modified = false;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] < a[i - 1]) {
                if (modified++) return false;
                (i - 2 < 0 || a[i - 2] <= a[i]) ? a[i - 1] = a[i] : a[i] = a[i - 1];
            }
        }
        return true;
    }
};
C++ - Without Modifying Input

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        bool modified = false;
        for (int i = 1, prev = a[0]; i < a.size(); i++) {
            if (a[i] < prev && modified++) return false;
            if (a[i] < prev && i - 2 >= 0 && a[i - 2] > a[i]) continue;
            prev = a[i];
        }
        return true;
    }
};
*/
