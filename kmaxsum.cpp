#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool rev(int a, int b)
{
    return b < a;
}
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    // Write your code here.
    sort(a.begin(), a.end(), rev);
    sort(b.begin(), b.end(), rev);
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    { // first combination
        pq.push(a[0] + b[i]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int sum = a[i] + b[j];
            if (sum >= pq.top())
            {
                pq.pop();
                pq.push(sum);
            }
            else
            {
                break;
            }
        }
    }

    for (int i = k - 1; i >= 0; i--)
    {
        ans[i] = pq.top();
        pq.pop();
    }
    return ans;
}