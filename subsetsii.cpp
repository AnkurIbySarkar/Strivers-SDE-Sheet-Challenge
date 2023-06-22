#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Func(int ind, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
        {
            continue;
        }
        ds.push_back(arr[i]);
        Func(i + 1, arr, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    Func(0, arr, ds, ans);
    return ans;
}