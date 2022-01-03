#include<iostream>
#include<math.h>
using namespace std;

double CalPowCore(double base, unsigned int abs_exponent) {
    if (abs_exponent == 0) {
        return 1.0;
    }
    double result = CalPowCore(base, abs_exponent>>1);
    result = pow(result, 2);
    if (abs_exponent & 1) {
        result *= base;
    }
    return result;
}

double CalPow(double base, int exponent) {
    if (abs(base) <= 1e-6) {
        if (exponent < 0) {
            cout << "Invalid Input!" << endl;
            return -1;
        } else {
            return 0.0;
        }
    }
    if (abs(base - 1.0) <= 1e-6) {
        return 1.0;
    }
    unsigned int abs_exponent = exponent < 0 ? abs(exponent) : exponent;
    double result = CalPowCore(base, abs_exponent);
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}

int main() {
    double base = 0.0000000001;
    int exponent = -3;
    cout << CalPow(base, exponent) << endl;

    return 0;
}