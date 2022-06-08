#include<bits/stdc++.h>
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
Node *findMiddle(Node *head) {
    Node *slow=head,*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}