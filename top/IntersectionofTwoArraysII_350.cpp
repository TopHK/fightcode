/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

vector<int> genIntersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> result;
    unordered_map<int,int> dict;
    for(const auto& num : nums1) dict[num]++;
    for(const auto& num : nums2)
    {
        if(dict.count(num) != 0)
        {
            result.push_back(num);
            dict[num]--;
            if(dict[num] == 0) dict.erase(num);
        }
    }
    return result;
}
