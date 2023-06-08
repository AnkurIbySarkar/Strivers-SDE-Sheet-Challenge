#include <iostream>
#include <vector>
using namespace std;
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int missing = -1;
    int repeating = -1;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
                cnt++;
        }
        if (cnt == 2)
            repeating = i;
        if (cnt == 0)
            missing = i;
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }

    return {missing, repeating};
}
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    vector<int> mpp(n, 0);
    int repeating = -1;
    int missing = -1;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mpp[i] > 1)
        {
            repeating = i;
        }
        if (mpp[i] == 0)
        {
            missing = i;
        }
    }
    return {missing, repeating};
}

pair<int, int> missingAndRepeating(vector<int> &a, int n)
{
    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = S - SN;

    long long val2 = S2 - S2N;

    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}