#include <iostream>
#include <vector>
using namespace std;
void findcombination(int ind, vector<int> &arr, int n, int k, vector<vector<int>> &ans,
                     vector<int> &ds)
{
    if (ind == n)
    {
        if (k == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[ind]);
    findcombination(ind + 1, arr, n, k - arr[ind], ans, ds);
    ds.pop_back();
    findcombination(ind + 1, arr, n, k, ans, ds);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> &arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    findcombination(0, arr, n, k, ans, ds);
    return ans;
}