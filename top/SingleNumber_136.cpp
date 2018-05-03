#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int singleNum = 0;
    for(const auto& num : nums)
    {
        singleNum ^= num;
    }
    return singleNum;
}

int main()
{
    vector<int> nums = {0, 1, 2, 1, 0, 2, 3, 5, 5};
    cout<<singleNumber(nums)<<endl;
    return 0;
}
