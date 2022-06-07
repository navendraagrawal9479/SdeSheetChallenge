#include <bits/stdc++.h> 
using namespace std;
int uniqueSubstrings(string input)
{
    unordered_map<int,int>m;
    int l=0,r=0,len=0;
    while(r<input.size()){
        if(m.find(input[r])!=m.end()){
            l=max(m[input[r]]+1,l);
        }
        len=max(len,r-l+1);
        m[input[r]]=r;
        r++;
    }
    return len;
}