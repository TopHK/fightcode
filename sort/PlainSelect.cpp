#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

void print(const vector<int> &nums)
{
    for(const auto &num : nums) cout<<num<<" ";
    cout<<endl;
}

class Solution
{
public:
    // 简单排序：O(n^2)；不稳定
    int PlainSelect(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; ++i)
        {
            int minNum = nums[i];
            int minPos = i;
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(nums[j] < minNum)
                {
                    minNum = nums[j];
                    minPos = j;
                }
            }
            swap(nums[i], nums[minPos]);
        }
        return 0;
    }

    // 快速排序：O(n*log(n));不稳定
    int PartitionArray(vector<int> &nums, int left, int right)
    {
        if(left >= right) return left;
        int pivot = nums[left];
        while(left < right)
        {
            while(left < right && nums[right] >= pivot)
                right--;
            if(left < right) nums[left++] = nums[right];

            while(left < right && nums[left] < pivot)
                left++;
            if(left < right) nums[right--] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
    void QuickSortCore(vector<int> &nums, int left, int right)
    {
        if(left >= right) return;
        int partitionPos = PartitionArray(nums, left, right);
        QuickSortCore(nums, left, partitionPos-1);
        QuickSortCore(nums, partitionPos+1, right);
    }
    int QuickSort(vector<int>& nums)
    {
        QuickSortCore(nums, 0, nums.size()-1);
        return 0;
    }
    // 堆排序：O(n*log(n));不稳定
    void AdjustHeap(vector<int> &nums, int len, int index)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int maxIndex = index;
        if(left < len && nums[left] > nums[maxIndex])
            maxIndex = left;
        if(right < len && nums[right] > nums[maxIndex])
            maxIndex = right;
        if(index != maxIndex)
        {
            swap(nums[index], nums[maxIndex]);
            AdjustHeap(nums, len, maxIndex);
        }
    }
    int HeapSort(vector<int>& nums)
    {
        int size = nums.size();
        for(int i = size/2-1; i >= 0; --i)
        {
            AdjustHeap(nums, size, i);
        }
        for(int i = size-1; i >= 1; --i)
        {
            swap(nums[0], nums[i]);
            AdjustHeap(nums, i, 0);
        }
        return 0;
    }

    // 冒泡排序：O(n^2);稳定
    int BubbleSort(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; ++i)
        {
            for(int j = 0; j < nums.size()-i-1; ++j)
            {
                if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
            }
        }
        return 0;
    }

    // 归并排序：O(n*log(n));稳定
    void MergeSortCore(vector<int>& nums, int left, int right, vector<int>& temp)
    {
        if(left >= right) return;
        int mid = left + ((right-left)>>1);
        MergeSortCore(nums, left, mid, temp);
        MergeSortCore(nums, mid+1, right, temp);
        int i = left, j = mid+1;
        int k = 0;
        while(i <= mid || j <= right)
        {
            if(i > mid)
            {
                temp[k++] = nums[j++];
            }
            else if(j > right)
            {
                temp[k++] = nums[i++];
            }
            else
            {
                if(nums[i] <= nums[j]) temp[k++] = nums[i++];
                else temp[k++] = nums[j++];
            }
        }
        for(int i = left,k=0; i <= right; ++i)
        {
            nums[i] = temp[k++];
        }
    }
    int MergeSort(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> temp(size,0);
        MergeSortCore(nums, 0, size-1, temp);
        return 0;
    }

    // 基数排序: O(n*log10(n));稳定
    int MaxBit(const vector<int> &nums)
    {
        int maxNum = *max_element(nums.begin(), nums.end());
        int maxBit = 0;
        int base = 1;
        while(maxNum >= base)
        {
            maxBit++;
            base *= 10;
        }
        return maxBit;
    }
    int RadixSort(vector<int>& nums)
    {
        int size = nums.size();
        if(size <= 1) return 0;
        int maxBits = MaxBit(nums);
        vector<int> temp(size, 0);
        vector<int> count(10, 0);
        int base = 1;
        for(int i = 1; i <= maxBits; ++i)
        {
            for(auto &c : count) c = 0;
            for(const auto &num : nums)
            {
                int bit = num / base % 10;
                count[bit]++;
            }
            for(int j = 1; j < 10; ++j) count[j] += count[j-1];
            for(int j = size-1; j >= 0; --j)
            {
                int num = nums[j];
                int bit = num / base % 10;
                temp[count[bit]-1] = num;
                count[bit]--;
            }
            for(int j = 0; j < size; ++j) nums[j] = temp[j];
            base *= 10;
        }
        return 0;
    }

    // 插入排序：O(n^2);稳定
    int InsertSort(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); ++i)
        {
            int temp = nums[i];
            int j = i-1;
            while(j >= 0 && nums[j] > temp)
            {
                nums[j+1] = nums[j];
                --j;
            }
            nums[j+1] = temp;
        }
        return 0;
    }

    // 希尔排序：比O(n^2)小;不稳定
    int ShellSort(vector<int>& nums)
    {
        int size = nums.size();
        for(int gap = size/2; gap >= 1; gap/=2)
        {
            for(int i = gap; i < size; i+=gap)
            {
                int temp = nums[i];
                int j = i-gap;
                while(j >= 0 && nums[j] > temp)
                {
                    nums[j+gap] = nums[j];
                    j-=gap;
                }
                nums[j+gap] = temp;
            }
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    //  堆排序、快速排序、希尔排序、直接选择排序不是稳定的排序算法，
    //  基数排序、冒泡排序、直接插入排序、折半插入排序、归并排序是稳定的排序算法。
    vector<int> nums = {9, 7, 81, 50, 6, 1, 2, 3, 4, 5};
    //solution.PlainSelect(nums);
    //solution.QuickSort(nums);
    //solution.HeapSort(nums);
    //solution.BubbleSort(nums);
    //solution.InsertSort(nums);
    //solution.MergeSort(nums);
    //solution.RadixSort(nums);
    solution.ShellSort(nums);
    print(nums);
    return 0;
}

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
