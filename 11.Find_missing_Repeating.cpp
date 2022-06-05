#include <bits/stdc++.h> 
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xoor=0;
    for(int i=0;i<n;i++){
        xoor=xoor^arr[i];
    }
    for(int i=1;i<=n;i++){
        xoor^=i;
    }
    int setbit=xoor & ~(xoor-1);
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(arr[i]&setbit)x=x^arr[i];
        else y=y^arr[i];
    }
    for(int i=1;i<=n;i++){
        if(i&setbit)x=x^i;
        else y=y^i;
    }
    int xcnt=0;
    for(int i=0;i<n;i++){
        if(x==arr[i])xcnt=1;
    }
    pair<int,int>ans;
    if(xcnt==1){
        ans.first=y;
        ans.second=x;
    }
    else{
        ans.first=x;
        ans.second=y;
    }
    return ans;
}