#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (!head)
        return head;
    LinkedListNode<int> *curr = head;
    while (curr)
    {
        LinkedListNode<int> *temp = new LinkedListNode<int>(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next->next;
    }
    curr = head;
    while (curr)
    {
        curr->next->random = !curr->random ? NULL : curr->random->next;
        curr = curr->next->next;
    }
    curr = head;
    LinkedListNode<int> *newhead = head->next, *front = head->next->next;
    while (front)
    {
        curr->next->next = front->next;
        curr->next = front;
        curr = front;
        front = front->next->next;
    }
    curr->next = NULL;
    return newhead;
}
