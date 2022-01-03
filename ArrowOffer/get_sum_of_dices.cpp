#include<iostream>
#include<math.h>
#include<vector>
#include<cstdio>
using namespace std;

void GetSumOfDicesCore(const int n, vector<int> &sum_vec, int index, int current_sum) {
    if (index > n) {
        ++sum_vec[current_sum - n];
        return;
    }
    for (int i = 1; i <= 6; ++i) {
        GetSumOfDicesCore(n, sum_vec, index + 1, current_sum + i);
    }
}

void GetSumOfDices(const int n) {
    double total = pow(6, n);
    vector<int> sum_vec(5 * n + 1, 0);
    GetSumOfDicesCore(n, sum_vec, 1, 0);
    for (int i = 0; i <= 5 * n; ++i) {
        int possible_sum = sum_vec[i];
        printf("%d-%d: %.4f\n", i, possible_sum, possible_sum / total);
    }
    printf("\n");
}

void GetSumOfDicesV2(const int n) {
    if (n <= 0) {
        return;
    }
    double total = pow(6, n);
    vector<int> sum_vec1(6 * n + 1, 0);
    // 初始化第一个筛子的点数
    for (int i = 1; i <= 6; ++i) {
        sum_vec1[i] = 1;
    }
    vector<int> sum_vec2(6 * n + 1, 0);
    // 动态规划求得第j个筛子的点数
    for (int j = 2; j <= n; ++j) {
        // j个筛子能达到的点数和为k
        for (int k = j; k <= 6 * j; ++k) {
            sum_vec2[k] = 0;
            for (int s = 1; s <= 6; ++s) {
                // k - s是j-1个筛子的点数和
                if (k - s >= j-1) {
                    sum_vec2[k] += sum_vec1[k-s];
                } else {
                    break;
                }
            }
        }
        // 把历史数据赋值给sum_vec1
        for (int k = j; k <= 6 * j; ++k) {
            sum_vec1[k] = sum_vec2[k];
        }
    }
    for (int i = n; i <= 6 * n; ++i) {
        int possible_sum = sum_vec1[i];
        printf("%d-%d: %.4f\n", i, possible_sum, possible_sum / total);
    }
}

int main() {
    int n = 3;
    GetSumOfDices(n);
    GetSumOfDicesV2(n);
    return 0;
}