#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < kArrays[i].size(); j++)
        {
            minh.push(kArrays[i][j]);
        }
    }
    vector<int> res;
    while (minh.size() > 0)
    {
        res.push_back(minh.top());
        minh.pop();
    }
    return res;
}
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> result;
    for (int i = 0; i < k; i++)
    {
        if (!kArrays[i].empty())
        {
            minHeap.push({kArrays[i][0], i});
            kArrays[i].erase(kArrays[i].begin());
        }
    }
    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        minHeap.pop();

        result.push_back(curr.first);

        int arrayIndex = curr.second;
        if (!kArrays[arrayIndex].empty())
        {
            minHeap.push({kArrays[arrayIndex][0], arrayIndex});
            kArrays[arrayIndex].erase(kArrays[arrayIndex].begin());
        }
    }

    return result;
}