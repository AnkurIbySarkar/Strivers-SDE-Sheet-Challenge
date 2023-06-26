#include <iostream>
#include <vector>
using namespace std;
int f(int i, int j, vector<vector<int>> &a)
{
    if (i == 0 && j == 0)
    {
        return a[i][j];
    }
    if (i < 0 || j < 0)
        return 1e9;
    int up = a[i][j] + f(i - 1, j, a);
    int left = a[i][j] + f(i, j - 1, a);
    return min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    return f(n - 1, m - 1, grid);
}
int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return a[i][j];
    }
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = a[i][j] + f(i - 1, j, a, dp);
    int left = a[i][j] + f(i, j - 1, a, dp);
    return dp[i][j] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, grid, dp);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;
                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[n - 1][m - 1];
}