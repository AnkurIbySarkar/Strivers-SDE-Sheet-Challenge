#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int ans = 0;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        int minheight = INT_MAX;
        for (int j = i; j < n; j++)
        {
            minheight = min(minheight, heights[j]);
            ans = max(ans, minheight * (j - i + 1));
        }
    }
    return ans;
}
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int ans = 0;
    int n = heights.size();
    stack<int> st;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            left[i] = 0;
        else
            left[i] = st.top() + 1;
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            right[i] = n - 1;
        else
            right[i] = st.top() - 1;
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (right[i] - left[i] + 1));
    }
    return ans;
}
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    stack<int> st;
    int ans = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            ans = max(ans, width * height);
        }
        st.push(i);
    }
    return ans;
}