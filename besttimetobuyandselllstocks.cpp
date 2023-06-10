#include <iostream>
#include <vector>
using namespace std;
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int diff = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (prices[i] < prices[j])
            {
                diff = prices[j] - prices[i];
            }
            ans = max(diff, ans);
        }
    }
    return ans;
}
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    int ans = prices[0], profit = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = prices[i] - ans;
        profit = max(profit, cost);
        ans = min(ans, prices[i]);
    }
    return profit;
}