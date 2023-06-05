#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int ans = -1;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto i : mpp)
    {
        if (i.second > n / 2)
        {
            ans = i.first;
            break;
        }
    }
    return ans;
}

// moore voting algorithm
int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int count = 0;
    int ans = 0;
    for (int num = 0; num < n; num++)
    {
        if (count == 0)
        {
            count = 1;
            ans = arr[num];
        }
        else if (arr[num] == ans)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans)
        {
            cnt1++;
        }
    }
    if (cnt1 > n / 2)
    {
        return ans;
    }
    return -1;
}