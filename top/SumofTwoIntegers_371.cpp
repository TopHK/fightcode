#include<iostream>
using namespace std;

int sumOfTwo(int a, int b)
{
    int carry = 1;
    int sum = 0;
    while(carry)
    {
        // ���ú�
        sum = a ^ b;

        // ����ý�λ
        carry = ((a & b) << 1);
        b = sum;
        a = carry;
    }
    return sum;
}

int main()
{
    cout<<sumOfTwo(1, 3)<<endl;
    return 0;
}
