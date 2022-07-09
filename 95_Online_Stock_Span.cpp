#include <bits/stdc++.h>
using namespace std;

vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    vector<int>ans(n);
    stack<int>s;
    for(int i = 0;i<n;i++){
        while(!s.empty() and price[i]>=price[s.top()])s.pop();
        if(s.empty())ans[i] = i+1;
        else{
            ans[i] = i-s.top();
        }
        s.push(i);
    }
    return ans;
}