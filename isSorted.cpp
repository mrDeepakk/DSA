#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSorted(string str){
    string s=str,s2=str;
    sort(str.begin(), str.end());
    reverse(s2.begin(),s2.end());
   
    if(str==s || str==s2){
        return true;
    }
    return false;

}


int main(){

    string s="cba";
    if(isSorted(s)){
        cout<<"YES";
    }
    else
        cout<<"NO";
    return 0;
}