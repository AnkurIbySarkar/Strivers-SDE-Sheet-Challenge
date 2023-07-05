#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kthLargest(vector<int> &arr, int size, int K)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    return arr[size - K];
}
int kthLargest(vector<int> &arr, int size, int K)
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > K)
            pq.pop();
    }

    return pq.top();
}