#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

Node* merge(Node *l1,Node *l2){
    if(!l2)return l1;
    if(!l1)return l2;
    if(l1->data>l2->data)return merge(l2,l1);
    Node *head=l1;
    
    while(l1 and l2){
        Node *temp;
        while(l1 and l1->data<l2->data){
            temp=l1;
            l1=l1->child;
        }
        temp->child=l2;
        swap(l1,l2);
    }
    head->next=NULL;
    return head;
}
Node* flattenLinkedList(Node* head) 
{
	if(!head or head->next==NULL)return head;
    head->next=flattenLinkedList(head->next);
    return merge(head,head->next);
}
