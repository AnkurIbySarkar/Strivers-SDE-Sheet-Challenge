#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
string fourSum(vector<int> nums, int target, int n)
{
    // Write your code here.
    // checking all possible quadruplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target)
                    {
                        return "Yes";
                    }
                }
            }
        }
    }
    return "No";
}
string fourSum(vector<int> nums, int target, int n)
{
    // Write your code here.
    // checking all possible quadruplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                int fourth = target - sum;

                if (hashset.find(fourth) != hashset.end())
                {
                    return "Yes";
                }
                hashset.insert(nums[k]);
            }
        }
    }
    return "No";
}
string fourSum(vector<int> nums, int target, int n)
{
    // Write your code here.
    // checking all possible quadruplets:
    sort(nums.begin(), nums.end());

    // calculating the quadruplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    return "Yes";
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }

    return "No";
}
