#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // Define the data members.
    queue<int> q;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element)
    {
        // Implement the push() function.
        q.push(element);
        int size = q.size() - 1;
        while (size--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (isEmpty())
            return -1;
        int e = q.front();
        q.pop();
        return e;
    }

    int top()
    {
        // Implement the top() function.
        if (isEmpty())
            return -1;
        return q.front();
    }
};