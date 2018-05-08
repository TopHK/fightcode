/*

*/

int maxArea(vector<int>& height)
{
    int area = 0;
    int left = 0;
    int right = height.size()-1;
    while(left < right)
    {
        int h = min(height[left], height[right]);
        area = max(area, (right-left)*h);
        while(left < right && height[left] <= h) ++left;
        while(left < right && height[right] <= h) --right;
    }
    return area;
}
