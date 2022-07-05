#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>>ans;
    int n=v.size();
    for(int i=0;i<(1<<n);i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                temp.push_back(v[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}