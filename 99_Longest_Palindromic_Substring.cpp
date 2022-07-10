#include <bits/stdc++.h>
using namespace std;

string longestPalinSubstring(string str)
{
    int n = str.size();
    int maxans=0;
    string ans = "";
    for(int k=0;k<n;k++){
        int i = k,j = k+1;
        while(i>=0 and j<n and str[i] == str[j]){
            if(j-i+1>maxans){
                maxans = j-i+1;
                ans = str.substr(i,j-i+1);
            }
            i--;
            j++;
        }
        i = k,j = k;
        while(i>=0 and j<n and str[i] == str[j]){
            if(j-i+1>maxans){
                maxans = j-i+1;
                ans = str.substr(i,j-i+1);
            }
            i--;
            j++;
        }
    }
    return ans;
}