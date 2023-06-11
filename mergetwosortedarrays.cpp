#include <iostream>
#include <vector>
using namespace std;
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    vector<int> temp;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            temp.push_back(arr1[i]);
            i++;
        }
        else
        {
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while (i < m)
    {
        temp.push_back(arr1[i]);
        i++;
    }
    while (j < n)
    {
        temp.push_back(arr2[j]);
        j++;
    }
    for (int i = 0; i < m + n; i++)
    {
        arr1[i] = temp[i];
    }
    return arr1;
}

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int i = m - 1, j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
    return arr1;
}