#include <iostream>
#include <vector>
using namespace std;
int findMinimumCoins(int amount)
{
    // Write your code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            cnt++;
        }
    }
    return cnt;
}
