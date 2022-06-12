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

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    // Write your code here.
    Node *d = new Node(0);
    d->next = head;

    Node *pre = d;
    Node *cur = d;
    Node *nex = d;

    int len = 0;
    while (cur->next != NULL)
    {
        cur = cur->next;
        len++;
    }

    int j = 0;
    while (len > 0 && j < n)
    {
        cur = pre->next;
        nex = cur->next;
        int x = (b[j] <= len) ? b[j] : len;
        if (x == 0)
        {
            j++;
            continue;
        }
        for (int i = 1; i < x; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        len -= b[j];
        j++;
    }
    return d->next;
}