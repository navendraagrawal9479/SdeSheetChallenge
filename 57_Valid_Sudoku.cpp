#include <bits/stdc++.h>
using namespace std;

bool isItSudoku(int board[9][9]) {
    set<string>s;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!=0){
                if(s.find("row"+to_string(i)+to_string(board[i][j]))!=s.end())return false;
                if(s.find("col"+to_string(j)+to_string(board[i][j]))!=s.end())return false;
                if(s.find("box"+to_string((i/3)*3+j/3)+to_string(board[i][j]))!=s.end())return false;
                s.insert("row"+to_string(i)+to_string(board[i][j]));
                s.insert("col"+to_string(j)+to_string(board[i][j]));
                s.insert("box"+to_string((i/3)*3+j/3)+to_string(board[i][j]));
            }
        }
    }
    return true;
}

int main(){
    int matrix[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<isItSudoku(matrix);
    return 0;
}