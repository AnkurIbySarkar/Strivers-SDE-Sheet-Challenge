#include <iostream>
#include <vector>
using namespace std;
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

long long merge(long long arr[], int low, int mid, int high)
{
    vector<long long> temp;
    int left = low;
    int right = mid + 1;
    long long cnt = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}
long long mergeSort(long long arr[], int low, int high)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    long long cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}