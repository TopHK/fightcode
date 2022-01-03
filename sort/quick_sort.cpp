#include<iostream>
#include<vector>
using namespace std;

int PartitionArr(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return left;
    }
    int pivotal = arr[left];
    int i = left, j = right;
    while (i <= j) {
        while (arr[j] > pivotal && i <= j) {
            --j;
        }
        while (arr[i] <= pivotal && i <= j) {
            ++i;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[j];
    arr[j] = pivotal;
    return j;
}

void QuickSortCore(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pos = PartitionArr(arr, left, right);
    QuickSortCore(arr, left, pos-1);
    QuickSortCore(arr, pos+1, right);
}

void QuickSort(vector<int>& arr) {
    QuickSortCore(arr, 0, arr.size()-1);
}

void PrintVector(const vector<int>& nums) {
    for (const auto& num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {4, 3, 1, 5, 2, 8, 7, 3, 5};
    QuickSort(nums);
    PrintVector(nums);

    return 0;
}