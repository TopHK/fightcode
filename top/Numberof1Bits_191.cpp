
int getOneCount(int num)
{
    int count = 0;
    while(num)
    {
        num &= (num-1);
        ++count;
    }
    return count;
}
