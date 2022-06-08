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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *d=new Node(0);
    Node *t=d;
    int c=0;
    while(head1 or head2){
        int sum=0;
        if(head1){
            sum+=head1->data;
            head1=head1->next;
        }
        if(head2){
            sum+=head2->data;
            head2=head2->next;
        }
        sum+=c;
        t->next=new Node(sum%10);
        c=sum/10;
        t=t->next;
    }
    while(c){
        t->next=new Node(c%10);
        c=c/10;
        t=t->next;
    }
    return d->next;
}