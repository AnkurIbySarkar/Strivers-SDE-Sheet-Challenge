#include <iostream>
#include <vector>
using namespace std;
// memoization
int countunique(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
        return dp[m][n];
    int up = countunique(m - 1, n, dp);
    int left = countunique(m, n - 1, dp);
    return dp[m][n] = up + left;
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countunique(m - 1, n - 1, dp);
}

// tabulation
int countunique(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;
            if (i > 0)
            {
                up = dp[i - 1][j];
            }
            if (j > 0)
            {
                left = dp[i][j - 1];
            }
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countunique(m, n, dp);
}