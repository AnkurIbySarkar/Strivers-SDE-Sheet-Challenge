#include <iostream>
#include <stack>
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for (char c : expression)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                return false; // Unmatched closing parenthesis or bracket
            }
            char ch = st.top();
            st.pop();
            if ((c == ')' && ch != '(') || (c == '}' && ch != '{') ||
                (c == ']' && ch != '['))
                return false;
        }
    }
    return st.empty();
}