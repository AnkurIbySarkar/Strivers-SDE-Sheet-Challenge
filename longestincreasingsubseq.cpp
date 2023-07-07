#include <iostream>
#include <vector>
using namespace std;
int f(int ind, int prev_ind, int arr[], int n)
{
    if (ind == n)
        return 0;
    int len = 0 + f(ind + 1, prev_ind, arr, n);
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
    {
        len = max(len, 1 + f(ind + 1, ind, arr, n));
    }
    return len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return f(0, -1, arr, n);
}
int f(int ind, int prev_ind, int arr[], int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    int len = 0 + f(ind + 1, prev_ind, arr, n, dp);
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
    {
        len = max(len, 1 + f(ind + 1, ind, arr, n, dp));
    }
    return dp[ind][prev_ind + 1] = len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, arr, n, dp);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev_ind + 1] = len;
        }
    }
    return dp[0][-1 + 1];
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> next(n + 1, 0), curr(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int len = 0 + next[prev_ind + 1];
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
            {
                len = max(len, 1 + next[ind + 1]);
            }
            curr[prev_ind + 1] = len;
        }
        next = curr;
    }
    return next[0];
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // Write Your Code here
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        auto it = std::lower_bound(res.begin(), res.end(), arr[i]);
        if (it == res.end())
            res.push_back(arr[i]);
        else
            *it = arr[i];
    }
    return res.size();
}
