#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first)return second;
    if(!second)return first;
    if(first->data>second->data)return sortTwoLists(second,first);
    Node<int>* head=first,*l1=first,*l2=second;
    while(l1 and l2){
        Node<int>* temp=l1;
        while(l1 and l1->data<=l2->data){
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return head;
}