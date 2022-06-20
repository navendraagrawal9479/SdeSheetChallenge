#include <bits/stdc++.h>
using namespace std;

void solve(int index,string &s,vector<string>&ans){
    if(index==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        solve(index+1,s,ans);
        swap(s[index],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string>ans;
    solve(0,s,ans);
    return ans;
}