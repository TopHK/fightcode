#include<iostream>
#include<math.h>
using namespace std;

int GetBitCount(int num) {
    int count = 0;
    while(num) {
        ++count;
        num /= 10;
    }
    return count;
}

int GetNumberOfOne(int num) {
    if (num <= 0) {
        return 0;
    }
    int bit_count = GetBitCount(num);
    int first_num = static_cast<int>(num / pow(10, bit_count-1));
    int one_count = 0;
    int rest_num = 0;
    if (first_num == 1) {
        rest_num = num - first_num * static_cast<int>(pow(10, bit_count-1));
        one_count = rest_num + 1;
    } else {
        one_count = static_cast<int>(pow(10, bit_count-1));
    }
    one_count += first_num * (bit_count - 1) * static_cast<int>(pow(10, bit_count-2));
//    cout << "num: " << num << ", bit_count: " << bit_count << ", first_num: " << first_num
//         << ", one_count: " << one_count << endl;
    return one_count += GetNumberOfOne(rest_num);
}

int main() {
    int num = 10;
    cout << GetNumberOfOne(num) << endl;
    return 0;
}