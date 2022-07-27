#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int frnt;
    int rear;
    int *arr;
    int currsize;
    int maxsize;

public:
    Queue()
    {
        frnt = -1;
        rear = -1;
        maxsize = 1000;
        currsize = 0;
        arr = new int[maxsize];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return currsize == 0;
    }

    void enqueue(int data)
    {
        if (currsize == maxsize)
            return;
        if (rear == -1)
        {
            rear = 0;
            frnt = 0;
        }
        else
            rear = (rear + 1) % maxsize;
        arr[rear] = data;
        currsize++;
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;
        int popped = arr[frnt];
        if (currsize == 1)
        {
            frnt = -1;
            rear = -1;
        }
        else
            frnt = (frnt + 1) % maxsize;
        currsize--;
        return popped;
    }

    int front()
    {
        if (frnt == -1)
            return -1;
        return arr[frnt];
    }
};