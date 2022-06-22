#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node,int c,int n,vector<vector<int>>&mat,vector<int>&color){
    for(int i=0;i<n;i++){
        if(i!=node and mat[node][i]==1 and color[i]==c)return false;
    }
    return true;
}
bool checkColor(int node,int n,int m,vector<vector<int>>&mat,vector<int>&color){
    if(node==n)return true;
    for(int i=1;i<=m;i++){
        if(isSafe(node,i,n,mat,color)){
            color[node]=i;
            if(checkColor(node+1,n,m,mat,color))return true;
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int>color(mat.size(),0);
    if(checkColor(0,mat.size(),m,mat,color))return "YES";
    return "NO";
}