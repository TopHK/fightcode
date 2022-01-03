#include<iostream>
#include<string>
using namespace std;

void PrintNumbersCore(int n, int index, string& num) {
    if (index >= n) {
        int pos = num.find_first_not_of('0');
        if (pos != string::npos) {
            cout << num.substr(pos) << " ";
        }
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        num[index] = '0' + i;
        PrintNumbersCore(n, index+1, num);
    }
}

void PrintNumbers(int n) {
    string num(n, '0');
    PrintNumbersCore(n, 0, num);
}

int main() {
    int n = 1;
    PrintNumbers(n);

    return 0;
}