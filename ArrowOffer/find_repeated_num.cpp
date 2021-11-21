#include <iostream>
#include <vector>
using namespace std;

int FindRepeatedNum(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] == i) {
            ++i;
        } else if (nums[i] == nums[nums[i]]){
            return nums[i];
        } else {
            int temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2, 3, 1, 0, 4, 5, 3};
    cout << FindRepeatedNum(nums) << endl;
    return 0;
}

