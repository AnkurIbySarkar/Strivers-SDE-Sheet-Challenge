#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool wordBreak(vector<string> &arr, int n, string &target)
{
    // Write your code here.
    set<string> st;
    for (int i = 0; i < arr.size(); i++)
        st.insert(arr[i]);
    int i = 0;
    string temp;
    int idx = -1;
    while (i < target.size())
    {
        temp += target[i];
        if (st.find(temp) != st.end())
        {
            idx = i;
            temp = "";
        }
        i++;
    }
    if (idx == target.size() - 1)
        return 1;
    return 0;
}