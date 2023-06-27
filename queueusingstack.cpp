#include <iostream>
#include <stack>
using namespace std;
class Queue
{
    // Define the data members(if any) here.
    stack<int> input, output;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        input.push(val);
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (input.empty())
            return -1;
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        int x = output.top();
        output.pop();
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return x;
    }

    int peek()
    {
        // Implement the peek() function here.
        if (input.empty())
            return -1;
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        int ans = output.top();
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return ans;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return input.empty();
    }
};