#include <bits/stdc++.h>
using namespace std;

string writeAsYouSpeak(int n) 
{
	// Write your code here.	
    if(n==1)return "1";
    if(n==2)return "11";
    string s = "11";
    for(int i=3;i<=n;i++){
        s+='%';
        string t = "";
        int cnt=1;
        for(int j=1;j<s.size();j++){
            if(s[j] != s[j-1]){
                t += to_string(cnt);
                t += s[j-1];
                cnt = 1;
            }
            else cnt++;
        }
        s = t;
    }
    return s;
}