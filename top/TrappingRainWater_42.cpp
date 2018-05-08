/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

int trap(vector<int>& height)
{
    int water = 0;
    int level = 0;
    int left = 0;
    int right = height.size()-1;

    while(left < right)
    {
        int lowerHeight = 0;
        if(height[left] < height[right]) lowerHeight = height[left++];
        else lowerHeight = height[right--];
        level = max(level, lowerHeight);
        water += (level - lowerHeight);
    }
    return water;
}
