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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prev=NULL,*nex,*curr=head;
    while(curr){
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}