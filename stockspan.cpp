#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> findSpans(vector<int> &price)
{
    // Write your code here.
    int n = price.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (price[j] <= price[i])
            {
                span++;
            }
            else
            {
                break;
            }
        }
        ans.push_back(span);
    }
    return ans;
}
vector<int> findSpans(vector<int> &price)
{
    // Write your code here.
    int n = price.size();
    vector<int> ans(n);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            ans[i] = 1;
        }
        else if (st.size() > 0 && st.top().first > price[i])
        {
            ans[i] = 1;
        }
        else if (st.size() > 0 && st.top().first <= price[i])
        {
            while (st.size() > 0 && st.top().first <= price[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = i + 1;
            }
            else
            {
                ans[i] = i - st.top().second;
            }
        }
        st.push({price[i], i});
    }
    return ans;
}