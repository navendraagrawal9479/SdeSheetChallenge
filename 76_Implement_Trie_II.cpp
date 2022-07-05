#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    int cntEndsWith=0;
    int cntPrefix=0;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increaseEnd(){cntEndsWith++;}
    void increasePrefix(){cntPrefix++;}
    void reduceEnd(){cntEndsWith--;}
    void reducePre(){cntPrefix--;}
    int cntEnd(){return cntEndsWith;}
    int cntPre(){return cntPrefix;}
};
class Trie{
    Node *root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        return node->cntEnd();
    }

    int countWordsStartingWith(string &word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        return node->cntPre();   
    }

    void erase(string &word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->reducePre();
            }
            else return;
        }
        node->reduceEnd();
    }
};