#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int Top;
    int max_size;

public:
    Stack(int capacity)
    {
        // Write your code here.
        arr = new int[capacity];
        Top = 0;
        max_size = capacity;
    }

    void push(int num)
    {
        // Write your code here.
        if (Top != max_size)
        {
            arr[Top] = num;
            Top++;
        }
    }

    int pop()
    {
        // Write your code here.
        if (Top != 0)
        {
            Top--;
            return arr[Top];
        }
        return -1;
    }

    int top()
    {
        // Write your code here.
        return (Top != 0) ? (arr[Top - 1]) : (-1);
    }

    int isEmpty()
    {
        // Write your code here.
        if (Top == 0)
        {
            return 1;
        }
        return 0;
    }

    int isFull()
    {
        // Write your code here.
        return (Top == max_size);
    }
};