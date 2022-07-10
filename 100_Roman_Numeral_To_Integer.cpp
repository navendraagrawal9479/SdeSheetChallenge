#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    // Write your code here
    unordered_map<char,int>m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int ans = 0, n = s.size();
    for(int i = 0; i<s.size(); i++){
        if(i!=n-1 and m[s[i]]<m[s[i+1]]){
            ans -= m[s[i]];
        }
        else ans += m[s[i]];
    }
    return ans;
}
