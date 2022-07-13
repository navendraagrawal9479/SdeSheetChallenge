#include <bits/stdc++.h>
using namespace std;

int compareVersions(string a, string b) 
{
    // Write your code here
    if(a == b)return 0;
    long long int v1=0,v2=0,v1len = a.size(),v2len = b.size(),i=0,j=0;
    while(i<v1len or j<v2len){
        v1 = 0,v2 = 0;
        while(i<v1len and a[i] != '.'){
            v1 = v1*10 + (a[i] - '0');
            i++;
        }
        while(j<v2len and b[j] != '.'){
            v2 = v2*10 + (b[j] - '0');
            j++;
        }
        if(v1>v2)return 1;
        else if(v1<v2)return -1;
        i++;
        j++;
    }
    return 0;
}