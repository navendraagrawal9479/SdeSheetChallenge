#include <bits/stdc++.h> 
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int>m;
    int xorr=0,cnt=0;
    for(int i=0;i<arr.size();i++){
        xorr=xorr^arr[i];
        if(xorr==x)cnt++;
        if(m.find(xorr^x)!=m.end()){
            cnt+=m[xorr^x];
        }
        m[xorr]++;
    }
    return cnt;
}