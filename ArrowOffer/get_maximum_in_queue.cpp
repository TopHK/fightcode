#include<iostream>
#include<deque>
#include<queue>
#include<vector>
using namespace std;

class MaxQueue {
private:
    queue<int> queue;
    deque<int> max_queue;
public:
    void push_back(const int value) {
        queue.push(value);
        while (!max_queue.empty() && max_queue.back() < value) {
            max_queue.pop_back();
        }
        while (max_queue.size() < queue.size()) {
            max_queue.push_back(value);
        }
    }

    void pop_front() {
        if (!queue.empty()) {
            queue.pop();
            max_queue.pop_front();
        }
    }

    int get_max() {
        return max_queue.front();
    }

    bool is_empty() {
        return queue.empty();
    }
};

int main() {
    MaxQueue max_queue;
    vector<int> nums = {5, 7, 3, 6, 8, 2};
    for (const auto& num : nums) {
        max_queue.push_back(num);
    }
    while (!max_queue.is_empty()) {
        cout << max_queue.get_max() << " ";
        max_queue.pop_front();
    }
    cout << endl;
    return 0;
}