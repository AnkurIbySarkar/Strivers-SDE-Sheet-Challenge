#include <iostream>
#include <vector>
using namespace std;
int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int maxResult = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod *= arr[j];
            maxResult = max(maxResult, prod);
        }
    }
    return maxResult;
}

int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int maxProduct = 1;
    int minProduct = 1;
    int maxResult = INT_MIN;

    for (auto num : arr)
    {
        if (num < 0)
            swap(maxProduct, minProduct);

        maxProduct = max(maxProduct * num, num);
        minProduct = min(minProduct * num, num);

        maxResult = max(maxResult, maxProduct);
    }

    return maxResult;
}
