#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    vector<int> result;
    int n = arr.size();
    if (k > n)
    {
        return result;
    }

    for (int i = 0; i <= n - k; ++i)
    {
        unordered_set<int> distinctSet;
        for (int j = i; j < i + k; ++j)
        {
            distinctSet.insert(arr[j]);
        }
        result.push_back(distinctSet.size());
    }

    return result;
}
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    vector<int> result;
    int n = arr.size();
    if (k > n)
    {
        return result;
    }

    unordered_map<int, int> freqMap;
    int distinctCount = 0;

    // Initialize the frequency map and distinct count for the first window
    for (int i = 0; i < k; ++i)
    {
        freqMap[arr[i]]++;
        if (freqMap[arr[i]] == 1)
        {
            distinctCount++;
        }
    }
    result.push_back(distinctCount);

    // Process the remaining windows
    for (int i = k; i < n; ++i)
    {
        // Remove the leftmost element from the previous window
        freqMap[arr[i - k]]--;
        if (freqMap[arr[i - k]] == 0)
        {
            distinctCount--;
        }

        // Add the rightmost element to the current window
        freqMap[arr[i]]++;
        if (freqMap[arr[i]] == 1)
        {
            distinctCount++;
        }

        result.push_back(distinctCount);
    }

    return result;
}
