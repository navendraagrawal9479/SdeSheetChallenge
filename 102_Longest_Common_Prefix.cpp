#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &str, int n)
{
    // Write your code here
    string ans="";
    for(int j=0;j<str[0].size();j++){
        char pre = str[0][j];
        for(int i = 0;i<n;i++){
            if(str[i][j] != pre)return ans;
        }
        ans+=pre;
    }
    return ans;
}


