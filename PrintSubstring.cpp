#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
//O(n^3)
void Substring(string str){
    for(int i=0;i<str.length();i++){
        for(int j=i;j<str.length();j++){
            for(int k=i;k<=j;k++){
                cout<<str[k];
            }
            cout<<endl;
        }
    }
}
void Substr(string str){
    for(int i=0;i<str.length();i++){
        for(int len=1;len<=str.length()-i;len++){
            cout<<str.substr(i,len)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    string txt="abcd";
    Substr(txt);
    return 0;
}