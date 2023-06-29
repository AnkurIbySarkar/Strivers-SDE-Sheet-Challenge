#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findcombination(int ind, vector<int> &arr, int n, int k, vector<vector<int>> &ans,
                     vector<int> &ds)
{
    if (k == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > k)
            break;
        ds.push_back(arr[i]);
        findcombination(i + 1, arr, n, k - arr[i], ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findcombination(0, arr, n, target, ans, ds);
    return ans;
}
