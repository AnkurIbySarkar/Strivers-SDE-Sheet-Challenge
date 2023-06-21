#include <iostream>
#include <vector>
#include <map>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for (int j = i; j < n; j++)
        {
            xorr ^= arr[j];
            if (xorr == x)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    map<int, int> mpp;
    int n = arr.size();
    int cnt = 0;
    int xr = 0;
    mpp[xr]++;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int k = xr ^ x;

        cnt += mpp[k];
        mpp[xr]++;
    }
    return cnt;
}