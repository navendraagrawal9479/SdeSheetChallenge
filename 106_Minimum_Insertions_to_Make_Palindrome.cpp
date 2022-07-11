#include <bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2){
    int n=s1.size(),m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
}
int lps(string s){
    string s2 = s;
    reverse(s2.begin(),s2.end());
    return lcs(s,s2);
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	return str.size() - lps(str);
}
