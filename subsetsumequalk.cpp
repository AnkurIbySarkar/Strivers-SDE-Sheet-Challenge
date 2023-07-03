#include <iostream>
#include <vector>
using namespace std;
bool subsetSumRecursive(vector<int> &numbers, int target, int index)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (numbers[0] == target);
    bool nottake = subsetSumRecursive(numbers, target, index - 1);
    bool take = false;
    if (target >= numbers[index])
    {
        take = subsetSumRecursive(numbers, target - numbers[index], index - 1);
    }

    return take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    return subsetSumRecursive(arr, k, n - 1);
}
bool subsetSumRecursive(vector<int> &numbers, int target, int index, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (numbers[0] == target);
    if (dp[index][target] != -1)
        return dp[index][target];
    bool nottake = subsetSumRecursive(numbers, target, index - 1, dp);
    bool take = false;
    if (target >= numbers[index])
    {
        take = subsetSumRecursive(numbers, target - numbers[index], index - 1, dp);
    }

    return dp[index][target] = take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSumRecursive(arr, k, n - 1, dp);
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        // Write your code here.
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (arr[0] <= k)
            dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool nottake = dp[i - 1][target];
                bool take = false;
                if (target >= arr[i])
                {
                    take = dp[i - 1][target - arr[i]];
                }
                dp[i][target] = take || nottake;
            }
        }
        return dp[n - 1][k];
    }
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<bool> prev(k + 1, false);

    prev[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(k + 1, false);
        curr[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool nottake = prev[target];
            bool take = false;
            if (target >= arr[i])
            {
                take = prev[target - arr[i]];
            }
            curr[target] = take || nottake;
        }
        prev = curr;
    }
    return prev[k];
}