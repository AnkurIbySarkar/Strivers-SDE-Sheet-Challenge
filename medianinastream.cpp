#include <iostream>
#include <queue>
using namespace std;
void balance(priority_queue<int> &maxh, priority_queue<int, vector<int>, greater<int>> &minh)
{
    if (maxh.size() > minh.size() + 1)
    {
        int z = maxh.top();
        minh.push(z);
        maxh.pop();
    }
    else if (maxh.size() < minh.size())
    {
        int z = minh.top();
        minh.pop();
        maxh.push(z);
    }
}
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < n; i++)
    {
        if (maxh.size() == 0 || maxh.top() > arr[i])
        {
            maxh.push(arr[i]);
        }
        else
        {
            minh.push(arr[i]);
        }

        balance(maxh, minh);

        if (i % 2 == 0)
        {
            cout << maxh.top() << " ";
        }
        else
        {
            cout << (maxh.top() + minh.top()) / 2 << " ";
        }
    }
}