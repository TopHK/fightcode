#include<iostream>
#include<vector>
using namespace std;

void CombineArray(int arr1[], int length1, int arr2[], int length2) {
    int i = length1 - 1;
    int j = length2 - 1;
    int k = length1 + length2 - 1;
    while (i >= 0 || j >= 0) {
        if (i >= 0 && j < 0) {
            arr1[k--] = arr1[i--];
        } else if (i < 0 && j >= 0) {
            arr1[k--] = arr2[j--];
        } else {
            if (arr1[i] >= arr2[j]) {
                arr1[k--] = arr1[i--];
            } else {
                arr1[k--] = arr2[j--];
            }
        }
    }
}

void PrintArr(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[9] = {1, 2, 4, 4, 5};
    int length1 = 5;
    int arr2[3] = {2, 3, 7};
    int length2 = 3;
    PrintArr(arr1, length1);
    PrintArr(arr2, length2);
    CombineArray(arr1, length1, arr2, length2);
    PrintArr(arr1, length1+length2);
    return 0;
}

