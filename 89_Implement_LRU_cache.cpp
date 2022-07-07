#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val,key;
    Node *next;
    Node *prev;
    Node(int key,int val){
        this->val = val;
        this->key = key;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache
{
    Node *head,*tail;
    int capacity;
    unordered_map<int,Node*>m;
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *node){
        Node *mostFrequent = head->next;
        head->next = node;
        node->prev= head;
        mostFrequent->prev = node;
        node->next = mostFrequent;
    }
    void deleteNode(Node* node){
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }

    int get(int key)
    {
        if(m.find(key)!=m.end()){
            Node *resnode = m[key];
            m.erase(key);
            int res = resnode->val;
            deleteNode(resnode);
            addNode(new Node(key,res));
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(m.find(key)!=m.end()){
            Node *resnode = m[key];
            m.erase(key);
            deleteNode(resnode);
        }
        else if(capacity == m.size()){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key] = head->next;
    }
};
