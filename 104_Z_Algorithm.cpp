#include <bits/stdc++.h>
using namespace std;

int zAlgorithm(string s, string p, int n, int m)
{
	string temp="";
    int cnt=0;
    if(m>n)return 0;
    for(int i=0;i<m;i++){
        temp+=s[i];
    }
    if(temp==p)cnt++;
    for(int i=m;i<n;i++){
        temp.erase(0,1);
        temp+=s[i];
        if(temp==p)cnt++;
    }
    return cnt;
}