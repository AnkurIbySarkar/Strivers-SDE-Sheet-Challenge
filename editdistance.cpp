#include <iostream>
#include <string>
#include <vector>
using namespace std;
int f(int i, int j, string str1, string str2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (str1[i] == str2[j])
        return f(i - 1, j - 1, str1, str2);
    return 1 + min(f(i - 1, j, str1, str2), min(f(i, j - 1, str1, str2), f(i - 1, j - 1, str1, str2)));
}
int f(int i, int j, string str1, string str2, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str1[i - 1] == str2[j - 1])
        return dp[i][j] = f(i - 1, j - 1, str1, str2, dp);
    return dp[i][j] = 1 + min(f(i - 1, j, str1, str2, dp), min(f(i, j - 1, str1, str2, dp), f(i - 1, j - 1, str1, str2, dp)));
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, str1, str2, dp);
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }

    return dp[n][m];
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 0; i <= m; i++)
    {
        prev[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
        }
        prev = curr;
    }

    return prev[m];
}