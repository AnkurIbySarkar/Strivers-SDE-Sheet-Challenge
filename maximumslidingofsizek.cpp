#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    vector<int> result;
    int n = nums.size();
    if (k > n)
    {
        return result;
    }

    for (int i = 0; i <= n - k; ++i)
    {
        int maxi = 0;
        for (int j = i; j < i + k; ++j)
        {
            maxi = max(maxi, nums[j]);
        }
        result.push_back(maxi);
    }

    return result;
}
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    vector<int> result;
    deque<int> dq;
    int n = nums.size();
    if (k > n)
    {
        return result;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && nums[i] > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}