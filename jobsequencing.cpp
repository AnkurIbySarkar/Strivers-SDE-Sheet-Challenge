#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct job
{
    int dead;
    int profit;
};
bool comparision(job a, job b)
{
    return (a.profit > b.profit);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    vector<job> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i].dead = jobs[i][0];
        arr[i].profit = jobs[i][1];
    }

    // Sort the jobs based on profit in descending order
    sort(arr.begin(), arr.end(), comparision);

    int max_deadline = 0;
    for (int i = 0; i < n; i++)
    {
        max_deadline = max(max_deadline, arr[i].dead);
    }

    vector<int> slot(max_deadline + 1, -1);

    int totalProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
            if (slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += arr[i].profit;
                break;
            }
    }

    return totalProfit;
}
