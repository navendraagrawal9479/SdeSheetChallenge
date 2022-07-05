#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node *node=root;
        for(int i=0;i<s.size();i++){
            if(!node->containsKey(s[i])){
                node->put(s[i],new Node());
            }
            node=node->get(s[i]);
        }
        node->setEnd();
    }
    bool containsprefix(string s){
        Node *node=root;
        for(int i=0;i<s.size();i++){
            if(node->containsKey(s[i])){
                node=node->get(s[i]);
                if(!node->isEnd())return false;
            }
            else return false;
        }
        return true;
    }
    
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto it:a){
        trie.insert(it);
    }
    string longest="";
    for(auto it:a){
        if(trie.containsprefix(it)){
            if(it.size()>longest.size()){
                longest=it;
            }
            else if(it.size()==longest.size() and it<longest){
                longest=it;
            }
        }
    }
    if(longest=="")return "None";
    return longest;
}