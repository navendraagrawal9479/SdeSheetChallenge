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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    if(k==0)return head;
    LinkedListNode<int> *d=new LinkedListNode<int>(0);
    d->next=head;
    LinkedListNode<int> *first=d,*second=d;
    for(int i=0;i<k;i++){
        second=second->next;
    }
    if(second->next==NULL){
        LinkedListNode<int> *t=head;
        head=head->next;
        delete t;
        return head;
    }
    while(second->next!=NULL){
        first=first->next;
        second=second->next;
    }
    LinkedListNode<int> *t=first->next;
    first->next=t->next;
    delete t;
    delete d;
    return head;
}