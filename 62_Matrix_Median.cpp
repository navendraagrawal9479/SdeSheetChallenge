#include <bits/stdc++.h>
using namespace std;

int findSmallerthanMid(vector<int>&row,int mid){
    int l=0,r=row.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(row[m]<=mid){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    int low=0,right,n=matrix.size(),m=matrix[0].size();
    right=1e9;
    while(low<=right){
        int mid=(low+right)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=findSmallerthanMid(matrix[i],mid);
        }
        if(cnt<=n*m/2)low=mid+1;
        else right=mid-1;
    }
    return low;
}