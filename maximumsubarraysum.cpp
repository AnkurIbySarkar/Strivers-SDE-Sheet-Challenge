#include <iostream>
using namespace std;
;
long long maxSubarraySum(int arr[], int n)
{

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}

long long maxSubarraySum(int arr[], int n)
{

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            ans = max(ans, sum);
        }
    }
    return ans;
}

long long maxSubarraySum(int arr[], int n)
{

    long long ans = LONG_MIN;
    long long sum = 0;
    bool allNegative = true;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > ans)
        {
            ans = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        if (arr[i] >= 0)
        {
            allNegative = false;
        }
    }
    if (allNegative)
    {
        return 0;
    }

    return ans;
}