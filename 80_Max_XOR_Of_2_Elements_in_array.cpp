#include <bits/stdc++.h>
using namespace std;

class Node{
    Node *links[2];
    public:
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node *node){
        links[bit] = node;
    }
    Node *get(int bit){
        return links[bit];
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int Max(int num){
        Node *node=root;
        int maxnum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containsKey(1-bit)){
                maxnum = maxnum | (1<<i);
                node = node->get(1-bit);
            }
            else node = node->get(bit);
        }
        return maxnum;
    }
};

int maximumXor(vector<int> &A)
{
    Trie t;
    for(int i=0 ;i<A.size();i++){
        t.insert(A[i]);
    }
    int maxi=0;
    for(auto it:A){
        maxi = max(maxi,t.Max(it));
    }
    return maxi;
}