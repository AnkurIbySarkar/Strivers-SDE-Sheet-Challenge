#include <iostream>
using namespace std;
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    if (m == 1)
    {
        return 0; // Not defined
    }
    long long result = 1;
    long long base = x % m;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = (result * base) % m;
        }
        base = (base * base) % m;
        n /= 2;
    }

    return int(result);
}