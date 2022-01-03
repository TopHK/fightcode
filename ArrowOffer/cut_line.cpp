#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int GetMaxProduct(int line_length) {
    if (line_length <= 1) {
        return 0;
    } else if (line_length == 2) {
        return 1;
    } else if (line_length == 3) {
        return 2;
    }
    vector<int> product(line_length + 1, 1);
    product[2] = 2;
    product[3] = 3;
    int max_product = 1;
    for (int i = 4; i <= line_length; ++i) {
        for (int j = 1; j <= line_length/2; ++j) {
            int current_product = product[j] * product[i-j];
            if (current_product > max_product) {
                max_product = current_product;
            }
        }
        product[i] = max_product;
    }
    return max_product;
}

int GetMaxProductV2(int line_length) {
    if (line_length <= 1) {
        return 0;
    } else if (line_length == 2) {
        return 1;
    } else if (line_length == 3) {
        return 2;
    }
    int three_count = line_length / 3;
    int res_length = line_length - three_count * 3;
    if (res_length == 1) {
        res_length += 3;
        three_count -= 1;
    }
    int two_count = res_length / 2;
    return static_cast<int>(pow(3, three_count) * pow(2, two_count));
}

int main() {
    int line_length = 9
            ;
    cout << GetMaxProduct(line_length) << endl;
    cout << GetMaxProductV2(line_length) << endl;
    return 0;
}
