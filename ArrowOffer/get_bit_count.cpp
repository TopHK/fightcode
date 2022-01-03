#include<iostream>
using namespace std;

int GetBitCount(int num) {
    int bit_count = 0;
    unsigned int flag = 1;
    while(flag) {
        if(num & flag) {
            ++bit_count;
        };
        flag <<= 1;
    }
    return bit_count;
}

int GetBitCountV2(int num) {
    int bit_count = 0;
    while(num) {
        num  = (num - 1) & num;
        ++bit_count;
    }
    return bit_count;
}

int main() {
    int num = 189;
    cout << GetBitCount(num) << endl;
    cout << GetBitCountV2(num) << endl;
    return 0;
}

