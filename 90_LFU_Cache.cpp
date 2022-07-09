#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    class Node{
        public:
        int key,value,cnt;
        Node *next,*prev;
        Node(int key,int value){
            cnt=1;
            this->key=key;
            this->value=value;
        }
    };
    struct List{
        int size;
        Node *head;
        Node *tail;
        List(){
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addFront(Node *newnode){
            Node *temp=head->next;
            newnode->next=temp;
            newnode->prev=head;
            temp->prev=newnode;
            head->next=newnode;
            size++;
        }
        void deletenode(Node *node){
            Node *tempprev=node->prev;
            Node *tempnext=node->next;
            tempprev->next=tempnext;
            tempnext->prev=tempprev;
            size--;
        }
    };
    unordered_map<int,List*>freqmap;
    unordered_map<int,Node*>keynode;
    int maxsize;
    int minfreq;
    int currsize;
    LFUCache(int capacity) {
        this->maxsize=capacity;
        minfreq=0;
        currsize=0;
    }
    void updatefreqlist(Node *node){
        keynode.erase(node->key);
        freqmap[node->cnt]->deletenode(node);
        if(node->cnt==minfreq and freqmap[node->cnt]->size==0){
            minfreq++;
        }
        List* nexthigherfreq=new List();
        if(freqmap.find(node->cnt+1)!=freqmap.end()){
            nexthigherfreq=freqmap[node->cnt+1];
        }
        node->cnt+=1;
        nexthigherfreq->addFront(node);
        freqmap[node->cnt]=nexthigherfreq;
        keynode[node->key]=node;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            Node *node=keynode[key];
            int val=node->value;
            updatefreqlist(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxsize==0)return;
        if(keynode.find(key)!=keynode.end()){
            Node *node=keynode[key];
            node->value=value;
            updatefreqlist(node);
        }
        else{
            if(currsize==maxsize){
                List *list=freqmap[minfreq];
                keynode.erase(list->tail->prev->key);
                freqmap[minfreq]->deletenode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq=1;
            List *listfreq=new List();
            if(freqmap.find(minfreq)!=freqmap.end()){
                listfreq=freqmap[minfreq];
            }
            Node *newnode=new Node(key,value);
            listfreq->addFront(newnode);
            keynode[key]=newnode;
            freqmap[minfreq]=listfreq;
        }
    }
};