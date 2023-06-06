#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int singleNonDuplicate(vector<int> &arr)
{
    // Write your code here
    unordered_map<int, int> mpp;
    for (auto i : arr)
    {
        mpp[arr[i]]++;
    }
    for (auto i : mpp)
    {
        if (i.second < 2)
        {
            return i.first;
        }
    }
    return -1;
}

int singleNonDuplicate(vector<int> &arr)
{
    // Write your code here
    int num = 0;
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
            {
                low = mid + 2;
            }
            else
            {
                high = mid;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return arr[low];
}