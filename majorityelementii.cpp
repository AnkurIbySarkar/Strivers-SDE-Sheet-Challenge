#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    if (n == 0)
        return ans;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > n / 3)
        {
            if (find(ans.begin(), ans.end(), arr[i]) == ans.end())
            {
                ans.push_back(arr[i]);
            }
        }
    }
    return ans;
}
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    unordered_map<int, int> mpp;
    if (n == 0)
        return ans;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto i : mpp)
    {
        if (i.second > n / 3)
        {
            ans.push_back(i.first);
        }
    }
    return ans;
}
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != arr[i])
        {
            el1 = arr[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && el1 != arr[i])
        {
            el2 = arr[i];
            cnt2 = 1;
        }
        else if (arr[i] == el1)
            cnt1++;
        else if (arr[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
            cnt1++;
        if (arr[i] == el2)
            cnt2++;
    }
    int mini = (int)(n / 3);
    if (cnt1 > mini)
        ans.push_back(el1);
    if (cnt2 > mini)
        ans.push_back(el2);

    return ans;
}