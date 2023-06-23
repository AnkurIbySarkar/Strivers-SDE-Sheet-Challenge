#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int frontIndex;
    int rearIndex;
    int max_size;
    int current_size;

public:
    Queue()
    {
        // Implement the Constructor
        max_size = 1000;
        arr = new int[max_size];
        frontIndex = 0;
        rearIndex = 0;
        current_size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return current_size == 0;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (current_size == max_size)
        {
            // Queue is full
            return;
        }
        arr[rearIndex] = data;
        rearIndex = (rearIndex + 1) % max_size;
        current_size++;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (isEmpty())
        {
            return -1;
        }
        int data = arr[frontIndex];
        frontIndex = (frontIndex + 1) % max_size; // Move frontIndex circularly
        current_size--;
        return data;
    }

    int front()
    {
        // Implement the front() function
        if (isEmpty())
        {
            return -1;
        }
        return arr[frontIndex];
    }
};