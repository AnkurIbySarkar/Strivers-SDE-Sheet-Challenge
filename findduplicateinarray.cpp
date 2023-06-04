#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findDuplicate(vector<int> &arr, int n)
{
    int ans = 0;
    unordered_map<int, int> mpp;
    for (auto i : arr)
    {
        mpp[i]++;
    }
    for (auto i : mpp)
    {
        if (i.second > 1)
        {
            ans = i.first;
        }
    }
    return ans;
}
