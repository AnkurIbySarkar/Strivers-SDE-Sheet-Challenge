#include <iostream>
#include <stack>
using namespace std;
void insertSorted(stack<int> &st, int value)
{
    if (st.empty() || (!st.empty() && value > st.top()))
    {
        st.push(value);
        return;
    }
    int top = st.top();
    st.pop();
    insertSorted(st, value);
    st.push(top);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
        return;
    int top = stack.top();
    stack.pop();
    sortStack(stack);
    insertSorted(stack, top);
}