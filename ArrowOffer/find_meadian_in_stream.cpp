#include<iostream>
#include<vector>
#include<set>
using namespace std;

void FindMeadianInStream(const vector<int>& nums) {
    multiset<int, greater<int>> left_set;
    multiset<int, less<int>> right_set;

    for (const auto& num:nums) {
        if (!right_set.empty() && num >= *(right_set.begin())) {
            right_set.insert(num);
        } else {
            left_set.insert(num);
        }
        if (left_set.size() >= right_set.size() + 2) {
            int left_largest_num = *(left_set.begin());
            left_set.erase(left_set.begin());
            right_set.insert(left_largest_num);
        } else if (right_set.size() >= left_set.size() + 1) {
            int right_smallest_num = *(right_set.begin());
            right_set.erase(right_set.begin());
            left_set.insert(right_smallest_num);
        }
        cout << left_set.size() << " " << right_set.size() << endl;
        float meadian = static_cast<float>(*(left_set.begin()));
        if(left_set.size() == right_set.size()) {
           meadian = (meadian + *(right_set.begin())) / 2;
        }
        cout << "Meadian: " << meadian << endl;
    }
    cout << endl;
}

int main() {
    vector<int> nums = {8, 2, 7, 3, 9, 5, 10};
    FindMeadianInStream(nums);
    return 0;
}