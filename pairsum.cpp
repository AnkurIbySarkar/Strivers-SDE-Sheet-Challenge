#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (sum == s)
            {
                ans.push_back({arr[i], arr[j]});
            }
        }
    }
    return ans;
}
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> ans;
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int target = s - arr[i];
        if (mpp.find(target) != mpp.end())
        {
            vector<int> res;
            int temp = mpp.find(target)->second;
            while (temp--)
            {
                res.push_back(arr[i]);
                res.push_back(target);
                sort(res.begin(), res.end());
                ans.push_back(res);
                res.clear();
            }
        }
        mpp[arr[i]]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}