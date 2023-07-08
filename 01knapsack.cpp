#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int f(int ind, int W, vector<int> &wt, vector<int> &val)
{
    if (ind == 0)
    {
        if (wt[ind] <= W)
            return val[0];
        return 0;
    }
    int not_take = f(ind - 1, W, wt, val);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val);
    }
    return max(not_take, take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    return f(n - 1, w, weights, values);
}
int f(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[ind] <= W)
            return val[0];
        return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int not_take = f(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
    }
    return dp[ind][W] = max(not_take, take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, weights, values, dp);
}
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {

            int not_take = dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            }
            dp[ind][w] = max(not_take, take);
        }
    }
    return dp[n - 1][W];
}
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    // Write your code here
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int i = wt[0]; i <= W; i++)
    {
        prev[i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {

            int not_take = prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = val[ind] + prev[w - wt[ind]];
            }
            curr[w] = max(not_take, take);
        }
        prev = curr;
    }
    return prev[W];
}
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    // Write your code here
	vector<int>prev(W+1,0);
	
    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int w=W; w>=0; w--){
    
		int not_take = prev[w];
		int take = INT_MIN;
                if (wt[ind] <= w) {
                  take = val[ind] + prev[w-wt[ind]];
                }
                prev[w] = max(not_take, take);
        }
    }
    return prev[W];
}