#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    int ans = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((at[i] >= at[j] && at[i] <= dt[j]) || (at[j] >= at[i] && at[j] <= dt[i]))
            {
                count++;
            }
        }
        ans = max(ans, count);
    }
    return ans;
}
int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    int platform = 1;
    int maxi = 1;
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        maxi = max(maxi, platform);
    }
    return maxi;
}