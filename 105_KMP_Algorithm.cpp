#include <bits/stdc++.h>
using namespace std;

bool findPattern(string p, string s)
{
    unordered_map<char,int>m;
    vector<int>table(p.size(),-1);
    for(int i=0;i<p.size();i++){
        if(m.find(p[i])==m.end()){
            m[p[i]]=i;
        }
        else{
            table[i]=m[p[i]];
        }
    }
    int i=0,j=-1;
    while(i<s.size()){
        if(s[i]==p[j+1]){
            i++;
            j++;
        }
        else if(j==-1 and s[i]!=p[j+1]){
            i++;
        }
        else{
            j=table[j];
        }
        if(j==p.size()-1)return true;
    }
    return false;
}