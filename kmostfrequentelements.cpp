#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    map<int, int> mpp;
    for (auto i : arr)
    {
        mpp[i]++;
    }
    priority_queue<pair<int, int>> pq;

    for (auto i : mpp)
    {
        pq.push({i.second, i.first});
    }
    for (int i = 1; i <= k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
