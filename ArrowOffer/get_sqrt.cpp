#include<iostream>
using namespace std;

int sqrt(int x) {
    if (x <= 1) {
        return x;
    }
    int left = 1, right = x / 2;
    while (left <= right) {
        int middle = ((right - left) >> 1) + left;
        int value = x / middle;
        if (value < middle) {
            right = middle - 1;
        } else if (value == middle){
            return middle;
        } else {
            if (x / (middle + 1) < (middle + 1)) {
                return middle;
            }
            left = middle + 1;
        }
    }
    return -1;
}

int main() {
    int num = 8;
    cout << sqrt(num) << endl;
    return 0;
}