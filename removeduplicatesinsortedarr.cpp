#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    arr.clear();
    for (int element : st)
    {
        arr.push_back(element);
    }
    return arr.size();
}
int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}