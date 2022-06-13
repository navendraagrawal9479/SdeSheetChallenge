#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *rotate(Node *head, int k)
{
    if (k == 0)
        return head;
    Node *d = new Node(0), *forward = d, *backward = d;
    d->next = head;
    Node *curr = head;
    int len = 0;
    while (curr)
    {
        len++;
        curr = curr->next;
    }
    k = k % len;
    for (int i = 0; i < k; i++)
    {
        forward = forward->next;
    }
    while (forward->next)
    {
        forward = forward->next;
        backward = backward->next;
    }
    forward->next = head;
    head = backward->next;
    backward->next = NULL;
    return head;
}