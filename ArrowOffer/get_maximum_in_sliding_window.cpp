#include<vector>
#include<deque>
#include<iostream>
using namespace std;

void GetMaximumInSlidingWindow(const vector<int>& nums, const int window_size) {
    deque<int> queue;
    for (int i = 0; i < nums.size(); ++i) {
//        cout << i << ": queue size: " << queue.size() << endl;
        if (queue.empty()) {
            queue.push_back(i);
        } else {
            while (!queue.empty() && nums[queue.back()] < nums[i]) {
                queue.pop_back();
            }
            queue.push_back(i);
            if (i >= window_size - 1) {
                cout << nums[queue.front()] << endl;
            }
            while (!queue.empty() && i >= queue.front() + window_size - 1) {
                queue.pop_front();
            }
        }
    }
}

int main() {
    vector<int> nums = {5, 6, 3, 9, 4, 2, 1, 11, 3, 8};
    int window_size = 3;
    GetMaximumInSlidingWindow(nums, window_size);
    return 0;
}