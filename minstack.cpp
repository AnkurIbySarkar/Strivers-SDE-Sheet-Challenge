#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class minStack
{
    // Write your code here.
    stack<pair<int, int>> st;

public:
    // Constructor
    minStack()
    {
        // Write your code here.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        // Write your code here.
        int mini = num;
        if (!st.empty())
        {
            mini = min(st.top().second, num);
        }
        st.push(make_pair(num, mini));
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (!st.empty())
        {
            int topElement = st.top().first;
            st.pop();
            return topElement;
        }
        return -1;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        // Write your code here.
        if (!st.empty())
        {
            return st.top().first;
        }
        return -1;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        // Write your code here.
        if (!st.empty())
        {
            return st.top().second;
        }
        return -1;
    }
};

class minStack
{
    // Write your code here.
    stack<long long> st;
    long long mini;

public:
    // Constructor
    minStack()
    {
        // Write your code here.
        while (!st.empty())
        {
            st.pop();
            mini = INT_MAX;
        }
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        // Write your code here.
        if (st.empty())
        {
            st.push(num);
            mini = num;
        }
        else
        {
            if (num < mini)
            {
                st.push(2 * num * 1LL - mini);
                mini = num;
            }
            else
            {
                st.push(num);
            }
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (st.empty())
            return -1;
        long long el = st.top();
        st.pop();
        if (el < mini)
        {
            int prevmini = mini;
            mini = 2 * mini - el;
            return prevmini;
        }
        return (int)el;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        // Write your code here.
        if (st.empty())
        {
            return -1;
        }
        long long el = st.top();
        if (el < mini)
            return (int)mini;
        return (int)el;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        // Write your code here.
        if (!st.empty())
        {
            return (int)mini;
        }
        return -1;
    }
};