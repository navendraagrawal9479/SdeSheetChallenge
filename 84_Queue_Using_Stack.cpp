#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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
        if (isEmpty())
            return -1;
        if (!output.empty())
        {
            int e = output.top();
            output.pop();
            return e;
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int e = output.top();
            output.pop();
            return e;
        }
    }

    int peek()
    {
        // Implement the peek() function here.
        if (isEmpty())
            return -1;
        if (!output.empty())
        {
            int e = output.top();
            return e;
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int e = output.top();
            return e;
        }
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        return input.empty() and output.empty();
    }
};