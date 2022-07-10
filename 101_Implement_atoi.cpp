#include <bits/stdc++.h>
using namespace std;

int atoi(string str) {
    // Write your code here.
    int sign = 1;
    int num = 0;
    int n = str.size();
    int i = 0;
    if(str[0] == '-'){
        sign = -1;
        i++;
    }
    for(;i<n;i++){
        if(str[i]>'9' or str[i]<'0')continue;
        else if(str[i]>='0' and str[i]<='9'){
            num = num*10 + (str[i] - '0');
        }
    }
    return sign*num;
}