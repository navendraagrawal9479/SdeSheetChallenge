#include <bits/stdc++.h> 
using namespace std;
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>>pascal;
    pascal.push_back({1});
    if(n==1)return pascal;
    pascal.push_back({1,1});
    if(n==2)return pascal;
    for(int i=2;i<n;i++){
        vector<long long int>level(i+1);
        level[0]=1;
        level[i]=1;
        for(int j=1;j<i;j++){
            level[j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
        pascal.push_back(level);
    }
    return pascal;
}
