#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    return {arr[k - 1], arr[n - k]};
}
#include <algorithm>
#include <queue>

int kthsmallest(vector<int> &arr, int n, int k)
{
    priority_queue<int> pq;
    int f = k - 1;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (f > 0)
    {
        pq.pop();
        f--;
    }
    return pq.top();
}
int kthlargest(vector<int> &arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int f = k - 1;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (f > 0)
    {
        pq.pop();
        f--;
    }
    return pq.top();
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int ksmall = kthsmallest(arr, n, k);
    int klarge = kthlargest(arr, n, k);
    return {klarge, ksmall};
}
int partition(vector<int> &arr, int low, int high)
{ // Return the partition position
    int pivot = arr[low];
    int left = low;
    int right = high;
    while (left < right)
    {
        while (arr[left] <= pivot && left <= high - 1)
        {
            left++;
        }
        while (arr[right] > pivot && right >= low + 1)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[low], arr[right]);
    return right;
}

// Code chunk 2: Perform quickselect algorithm to find the kth smallest or kth largest element
int quickselect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex < k)
        {
            return quickselect(arr, pivotIndex + 1, high, k);
        }
        else
        {
            return quickselect(arr, low, pivotIndex - 1, k);
        }
    }
    return -1;
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int low = 0, high = n - 1;
    int ksmall = quickselect(arr, low, high, k - 1);
    int klarge = quickselect(arr, low, high, n - k);
    return {ksmall, klarge};
}