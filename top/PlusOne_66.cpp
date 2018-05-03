vector<int> plusOne(vector<int>& digits)
{
    int size = digits.size();
    vector<int> result(size+1);
    int flag = 0;
    int i = size;
    int p = size-1;
    while(p >= 0 || flag)
    {
        int curNum = digits[p--] + flag;
        result[i--] = curNum % 10;
        flag = curNum / 10;
    }
    if(i == 0) result.erase(result.begin());
    return result;
}
