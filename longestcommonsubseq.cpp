#include <iostream>
#include <vector>
using namespace std;
int f(string s, string t, int n, int m)
{
    if (n < 0 || m < 0)
        return 0;
    if (s[n] == t[m])
        return 1 + f(s, t, n - 1, m - 1);
    return max(f(s, t, n - 1, m), f(s, t, n, m - 1));
}
int lcs(string s, string t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();
    return f(s, t, n - 1, m - 1);
}
int f(string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s[n] == t[m])
        return dp[n][m] = 1 + f(s, t, n - 1, m - 1, dp);
    return dp[n][m] = max(f(s, t, n - 1, m, dp), f(s, t, n, m - 1, dp));
}
int lcs(string s, string t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return f(s, t, n - 1, m - 1, dp);
}
int lcs(string s, string t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}
int lcs(string s, string t)
{
    // Write your code here
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    return prev[m];
}