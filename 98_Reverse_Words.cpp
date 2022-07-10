#include <bits/stdc++.h>
using namespace std;

void reverseStr(string &s){
    int i=0,j=s.size()-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
}
string reverseString(string str)
{
    int n = str.size();
    string word = "";
    string result = "";
    int sc = 0;
    for(int i=n-1;i>=0;i--){
        if(str[i]!=' '){
            sc = 0;
            word+=str[i];
        }
        if(str[i] == ' ' or (i == 0 and str[i] != ' ')){
            sc++;
            reverseStr(word);
            if(sc == 1 and result.size() == 0){
                result += word;
                word = "";
            }
            else if(sc == 1 and result.size()>0){
                result += " " + word;
                word = "";
            }
        }
    }
    return result;
}