#include <iostream>
#include <vector>
using namespace std;
int longestSubSeg(vector<int> &arr, int n, int k)
{
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt0 = 0;

        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
            {
                cnt0++;
            }

            if (cnt0 <= k)
            {
                int length = j - i + 1;
                maxLength = max(maxLength, length);
            }
        }
    }

    return maxLength;
}
int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // Write your code here.
    int maxi = 0;
    int cnt0 = 0;

    for (int i = 0, j = 0; j < n; j++)
    {
        // if we find 0 increment count
        if (arr[j] == 0)
        {
            cnt0++;
        }

        // if we encounter that cnt0 is greater than k, increment the j counter
        while (cnt0 > k)
        {
            if (arr[i] == 0)
            {
                cnt0--;
            }
            i++;
        }

        maxi = max(maxi, j - i + 1);
    }

    return maxi;
}
