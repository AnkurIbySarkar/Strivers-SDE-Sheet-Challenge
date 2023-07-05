#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool knows(int i, int j)
{
    // Your implementation here
    // Return true if person i knows person j, otherwise false
    return false;
}
int findCelebrity(int n)
{
    // Write your code here.
    for (int i = 0; i < n; ++i)
    {
        bool isCelebrity = true;
        for (int j = 0; j < n; ++j)
        {
            if (i != j && (knows(i, j) || !knows(j, i)))
            {
                isCelebrity = false;
                break;
            }
        }
        if (isCelebrity)
        {
            for (int k = 0; k < n; ++k)
            {
                if (k != i && !knows(k, i))
                {
                    isCelebrity = false;
                    break;
                }
            }
            if (isCelebrity)
            {

                return i;
            }
        }
    }
    // If no celebrity is found, return -1
    return -1;
}
int findCelebrity(int n)
{
    // Write your code here.
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(a, b))
            st.push(b);
        else
            st.push(a);
    }
    int c = st.top();
    for (int i = 0; i < n; i++)
    {
        if ((c != i) && (knows(c, i) || !knows(i, c)))
            return -1;
    }
    return c;
}