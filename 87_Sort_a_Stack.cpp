#include <bits/stdc++.h>
using namespace std;

void correct(int x,stack<int> &stack){
    if(stack.empty() or x>stack.top()){
        stack.push(x);
    }
    else{
        int a = stack.top();
        stack.pop();
        correct(x,stack);
        stack.push(a);
    }
}
void sortStack(stack<int> &stack)
{
	if(!stack.empty()){
        int a = stack.top();
        stack.pop();
        sortStack(stack);
        correct(a,stack);
    }
}