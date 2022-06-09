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

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *first = firstHead;
    Node *second = secondHead;
    while (first != second and (first or second))
    {
        first = first == NULL ? secondHead : first->next;
        second = second == NULL ? firstHead : second->next;
    }
    return (!first or !second) ? -1 : first->data;
}