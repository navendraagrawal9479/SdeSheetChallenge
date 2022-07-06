#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    unordered_map<char,int>m;
    m['{'] = 1;
    m['['] = 2;
    m['('] = 3;
    m['}'] = -1;
    m[']'] = -2;
    m[')'] = -3;
    stack<char>s;
    for(auto it:expression){
        if(m[it]>0){
            s.push(it);
        }
        else{
            if(s.empty())return false;
            if(m[it]+m[s.top()]!=0)return false;
            else s.pop();
        }
    }
    if(s.empty())return true;
    return false;
}