#include <iostream>
using namespace std;
int NthRoot(int n, int m)
{
    // Write your code here.
    int guess = 1;
    while (pow(guess, n) < m)
    {
        guess++;
    }
    if (pow(guess, n) != m)
    {
        return -1;
    }
    return guess;
}
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int NthRoot(int n, int m)
{
    // Write your code here.
    int low = 1;
    int high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midi = func(mid, n, m);
        if (midi == 1)
        {
            return mid;
        }
        else if (midi == 0)
        {
            low = mid + 1;
        }
        else if (midi == 2)
        {
            high = mid - 1;
        }
    }
    return -1;
}