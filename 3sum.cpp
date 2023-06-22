#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.

    vector<int> temp;
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == K)
                {
                    temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.

    vector<int> temp;
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int target = K - (arr[i] + arr[j]);
            if (hashset.find(target) != hashset.end())
            {
                temp = {arr[i], arr[j], target};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == K)
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
            else if (sum < K)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return ans;
}