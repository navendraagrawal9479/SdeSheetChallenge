#include <bits/stdc++.h>
using namespace std;


int findCelebrity(int n) {
 	// Write your code here.
    stack<int>s;
    for(int i=0;i<n;i++)s.push(i);
    while(s.size() != 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(a,b) and !knows(b,a)){
            s.push(b);
        }
        else if(knows(b,a) and !knows(a,b)){
            s.push(a);
        }
        if(s.empty()) return -1;
    }
    int c = s.top();
    int zero = 0,one = 0;
    for(int i=0;i<n;i++){
        if(!knows(c,i))zero++;
        if(knows(i,c))one++;
    }
    if(zero == n and one == n-1)return c;
    return -1;
}