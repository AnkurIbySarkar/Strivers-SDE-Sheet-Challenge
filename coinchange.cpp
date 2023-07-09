#include <iostream>
#include <vector>
using namespace std;
long f(int index, int value, int *denominations)
{
    if (index == 0)
        return (value % denominations[0] == 0);
    int not_take = f(index - 1, value, denominations);
    int take = 0;
    if (denominations[index] <= value)
        take = f(index, value - denominations[index], denominations);
    return take + not_take;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    return f(n - 1, value, denominations);
}
long f(int index, int value, int *denominations, vector<vector<long>> &dp)
{
    if (index == 0)
        return (value % denominations[0] == 0);
    if (dp[index][value] != -1)
        return dp[index][value];
    long not_take = f(index - 1, value, denominations, dp);
    long take = 0;
    if (denominations[index] <= value)
        take = f(index, value - denominations[index], denominations, dp);
    return dp[index][value] = take + not_take;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int i = 0; i <= value; i++)
    {
        dp[0][i] = (i % denominations[0] == 0);
    }
    for (int index = 1; index < n; index++)
    {
        for (int j = 0; j <= value; j++)
        {
            long not_take = dp[index - 1][j];
            long take = 0;
            if (denominations[index] <= j)
                take = dp[index][j - denominations[index]];
            dp[index][j] = take + not_take;
        }
    }
    return dp[n - 1][value];
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<long> prev(value + 1, 0), curr(value + 1, 0);
    for (int i = 0; i <= value; i++)
    {
        prev[i] = (i % denominations[0] == 0);
    }
    for (int index = 1; index < n; index++)
    {
        for (int j = 0; j <= value; j++)
        {
            long not_take = prev[j];
            long take = 0;
            if (denominations[index] <= j)
                take = curr[j - denominations[index]];
            curr[j] = take + not_take;
        }
        prev = curr;
    }
    return prev[value];
}