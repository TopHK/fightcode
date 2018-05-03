/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

bool powerOfThree(int n)
{
    const int MaxNum = 1162261467;
    if(n <= 0 || n > MaxNum) return false;
    return (MaxNum % n) == 0;
}
