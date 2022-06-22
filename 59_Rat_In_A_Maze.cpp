#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& maze,vector<vector<int>>& ans,vector<vector<int>>& vis,int n,int i,int j){
    if(i==n-1 && j==n-1){
        vector<int> ds;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ds.push_back(vis[i][j]);
            }
        }
        ans.push_back(ds);
        return;
    }
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    for(int z=0;z<4;z++){
        int x=dx[z]+i,y=dy[z]+j;
        if(x<0 || y<0 || x>=n || y>=n) continue;
        if(maze[x][y] && !vis[x][y]){
            vis[x][y]=1;
            solve(maze,ans,vis,n,x,y);
            vis[x][y]=0;
        }
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;
    if(n==0) return ans;
    
    vector<vector<int>> vis(n,vector<int>(n,0));
    if(maze[0][0]==1) {
        vis[0][0]=1;
        solve(maze,ans,vis,n,0,0);
    }
    return ans;
}