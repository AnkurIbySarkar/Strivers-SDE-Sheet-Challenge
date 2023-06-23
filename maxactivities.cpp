#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct job
{
    int start;
    int end;
};
bool comp(struct job a, struct job b)
{
    return (a.end < b.end);
}
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    int n = start.size();
    vector<job> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].end = finish[i];
    }
    sort(arr.begin(), arr.end(), comp);
    int ans = 1;
    int end = arr[0].end;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].start >= end)
        {
            end = arr[i].end;
            ans++;
        }
    }
    return ans;
}