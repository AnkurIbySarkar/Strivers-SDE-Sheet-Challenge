#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}
int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code here
    unordered_map<int, int> mpp;
    int ans = 0;
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            ans = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                ans = max(ans, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return ans;
}