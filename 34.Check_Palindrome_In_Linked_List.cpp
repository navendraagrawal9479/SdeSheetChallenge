#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *pre = NULL;
    LinkedListNode<int> *nex;
    while (curr)
    {
        nex = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nex;
    }
    return pre;
}
bool isPalindrome(LinkedListNode<int> *head)
{
    if (!head or !head->next)
        return true;
    LinkedListNode<int> *fast = head, *slow = head;
    while (fast->next)
    {
        fast = fast->next;
        if (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast = head;
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow)
    {
        if (slow->data != fast->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}