#include<iostream>
#include<vector>
using namespace std;

long long maxWater(vector<int>& arr) {
    if (arr.size() < 3) {
        return 0;
    }
    long long total_water = 0;
    int left = 0, right = arr.size()-1;
    int min_height = min(arr.front(), arr.back());
    while (left < right) {
        if (arr[left] < arr[right]) {
            ++left;
            if (arr[left] < min_height) {
                total_water += (min_height - arr[left]);
            } else {
                min_height = min(arr[left], arr[right]);
            }
        } else {
            --right;
            if (arr[right] < min_height) {
                total_water += (min_height - arr[right]);
            } else {
                min_height = min(arr[left], arr[right]);
            }
        }
    }
    return total_water;
}

int main() {
    vector<int> nums = {3,1,2,5,2,4};
    cout << maxWater(nums) << endl;
    return 0;
}