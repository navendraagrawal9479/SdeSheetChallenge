#include<bits/stdc++.h>
using namespace std;
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    unordered_map<char,int>freq;
    for(auto it:str1){
        freq[it]++ ;
    }
    for(auto it:str2){
        freq[it]-- ;
    }
    for(auto it:freq){
        if(it.second != 0)return false;
    }
    return true;
}