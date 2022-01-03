#include<vector>
#include<string>
#include<queue>
#include<map>
#include<iostream>
using namespace  std;

struct cmp {
    bool operator() (const pair<string, int>& p1, const pair<string, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;  // 数量相同时，key按照字母顺序排列
        } else {
            return p1.second > p2.second;  // 小顶堆, greater
        }
    }
};

vector<vector<string> > topKstrings(vector<string>& strings, int k) {
    vector<vector<string>> results;
    map<string, int> counter;
    for (const auto& str : strings) {
        ++counter[str];
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> queue;
    for (const auto& pair : counter) {
        if (queue.size() < k ||
            pair.second > queue.top().second ||  // 更大的数字需要push
            (pair.second == queue.top().second && pair.first < queue.top().first)) {
            queue.push(pair);
        }
        if (queue.size() > k) {
            queue.pop();
        }
    }
    while (!queue.empty()) {
        results.push_back(vector<string> {queue.top().first, to_string(queue.top().second)});
        queue.pop();
    }
    reverse(results.begin(), results.end());
    return results;
}

int main() {
    vector<string> strings = {
//            "123","123","231","32"
            "abcd","abcd","abcd","pwb2","abcd","pwb2","p12"
    };
    int k = 3;
    vector<vector<string> > results = topKstrings(strings, k);
    for (const auto& pair : results) {
        cout << pair[0] << ":" << pair[1] << endl;
    }
    return 0;
}