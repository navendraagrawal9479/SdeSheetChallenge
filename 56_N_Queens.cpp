#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007

void solve(int col,vector<int>&left,vector<int>&upperLeft,vector<int>&lowerLeft,vector<vector<int>>&ans,vector<vector<int>>&chessBoard,int n){
    if(col==n){
        ans= chessBoard;
        return;
    }
    for(int row=0;row<n;row++){
        if(left[col]==0 and upperLeft[n-1+col-row]==0 and lowerLeft[row+col]==0)         {
            chessBoard[row][col]==1;
            left[row]==1;
            upperLeft[n-1+col-row]==1;
            lowerLeft[row+col]==1;
            solve(col+1,left,upperLeft,lowerLeft,ans,chessBoard,n);
            chessBoard[row][col]==0;
            left[row]==0;
            upperLeft[n-1+col-row]==0;
            lowerLeft[row+col]==0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int>left(n,0),upperLeft(2*n-1,0),lowerLeft(2*n-1,0);
    vector<vector<int>>chessBoard(n,vector<int>(n,0));
    vector<vector<int>>ans;
    solve(0,left,upperLeft,lowerLeft,ans,chessBoard,n);
    return ans;
}
