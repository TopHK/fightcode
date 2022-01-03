#include<iostream>
#include<math.h>
using namespace std;

int GetCertainBit(int n) {
    if (n < 1) {
        return -1;
    }
    int bit_count = 1;
    while (n > 0) {
        n -= bit_count * static_cast<int>(pow(10, bit_count) - pow(10, bit_count-1));
        ++bit_count;
    }
    --bit_count;
    n *= -1;
    int certain_num = static_cast<int>(pow(10, bit_count) - n / bit_count - 1);
    int rest_bit = n - n / bit_count * bit_count + 1;
//    cout << bit_count << " " << n << " " << rest_bit << " " << certain_num << endl;
    int result = 0;
    while (rest_bit) {
        result = certain_num % 10;
        certain_num /= 10;
        --rest_bit;
    }
    return result;
}

int main() {
    int n = 19;
    cout << GetCertainBit(n) << endl;
    return 0;
}