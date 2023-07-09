#include <iostream>
#include <vector>
using namespace std;
int f(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr) + f(k + 1, j, arr);
        if (steps < mini)
            mini = steps;
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    return f(1, N - 1, arr);
}

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    int mini = 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
        if (steps < mini)
            mini = steps;
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N - 1, arr, dp);
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--)
    {

        for (int j = i + 1; j < N; j++)
        {

            int mini = INT_MAX;

            // partioning loop
            for (int k = i; k <= j - 1; k++)
            {

                int ans = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}