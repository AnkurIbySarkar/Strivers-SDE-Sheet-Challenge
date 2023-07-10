#include <iostream>
#include <vector>
using namespace std;
int f(int index, int n, vector<int> &price)
{
    if (index == 0)
    {
        return n * price[0];
    }
    int not_take = f(index - 1, n, price);
    int take = INT_MIN;
    int rodlength = index + 1;
    if (rodlength <= n)
    {
        take = price[index] + f(index, n - rodlength, price);
    }
    return max(not_take, take);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    return f(n - 1, n, price);
}
int f(int index, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return n * price[0];
    }
    if (dp[index][n] != -1)
        return dp[index][n];
    int not_take = f(index - 1, n, price, dp);
    int take = INT_MIN;
    int rodlength = index + 1;
    if (rodlength <= n)
    {
        take = price[index] + f(index, n - rodlength, price, dp);
    }
    return dp[index][n] = max(not_take, take);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int not_take = dp[i - 1][j];
            int take = INT_MIN;
            int rodlength = i + 1;
            if (rodlength <= j)
            {
                take = price[i] + dp[i][j - rodlength];
            }
            dp[i][j] = max(not_take, take);
        }
    }
    return dp[n - 1][n];
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int not_take = prev[j];
            int take = INT_MIN;
            int rodlength = i + 1;
            if (rodlength <= j)
            {
                take = price[i] + curr[j - rodlength];
            }
            curr[j] = max(not_take, take);
        }
        prev = curr;
    }
    return prev[n];
}
