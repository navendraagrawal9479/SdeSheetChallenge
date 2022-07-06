#include <bits/stdc++.h>
using namespace std;

class Stack {
    vector<int>s;
    int size;
public:
    
    Stack(int capacity) {
        size = capacity;
    }

    void push(int num) {
        if(size == s.size())return;
        s.push_back(num);
    }

    int pop() {
        if(s.empty())return -1;
        int p = s.back();
        s.pop_back();
        return p;
    }
    
    int top() {
        if(s.empty())return -1;
        return s.back();
    }
    
    int isEmpty() {
        return s.empty();
    }
    
    int isFull() {
        return s.size() == size;
    }
    
};