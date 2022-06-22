#include <bits/stdc++.h>
using namespace std;

void solve(int index,string &s,vector<string>&dictionary,vector<string>&ans,string present){
    if(index==s.size()){
        present.pop_back();
        ans.push_back(present);
        return;
    }
    for(int i=index;i<s.size();i++){
        string temp=s.substr(index,i-index+1);
        for(int k=0;k<dictionary.size();k++){
            if(temp==dictionary[k]){
                string x=present;
                present+=temp+" ";
                solve(i+1,s,dictionary,ans,present);
                present=x;
                break;
            }
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string>ans;
    string present="";
    solve(0,s,dictionary,ans,present);
    return ans;
}