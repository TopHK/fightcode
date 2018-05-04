/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

int countPrimes(int n)
{
    vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;
    for(int i = 2; i <= (int)sqrt(n); ++i)
    {
        if(primes[i])
        {
            for(int j = i*i; j < n; j+=i)
            {
                primes[j] = false;
            }
        }
    }
    return count(primes.begin(), primes.end(), true);
}
