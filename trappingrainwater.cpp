#include <iostream>
#include <algorithm>
using namespace std;
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long waterTrapped = 0;

    for (int i = 0; i < n; i++)
    {
        int j = i;
        long leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long waterTrapped = 0;

    long prefix[n], suffix[n];
    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    for (int i = 1; i < n; i++)
    {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}
long getTrappedWater(long *arr, int n)
{
    // Write your code here.
    long waterTrapped = 0;

    int left = 0, right = n - 1;
    long maxleft = 0, maxright = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= maxleft)
            {
                maxleft = arr[left];
            }
            else
            {
                waterTrapped += maxleft - arr[left];
            }
            left++;
        }
        else
        {
            if (arr[right] >= maxright)
            {
                maxright = arr[right];
            }
            else
            {
                waterTrapped += maxright - arr[right];
            }
            right--;
        }
    }
    return waterTrapped;
}