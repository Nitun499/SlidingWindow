#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
void Map(int* arr,int size){
    unordered_map<int,int> mp;
    for(int i=0;i<size;i++){
        mp[arr[i]]++;
    }
    mp[7]++;
    mp[8]++;
    for(auto it= mp.begin(); it!=mp.end();it++){
        cout<<(it->first)<<"->"<<it->second<<endl;
    }
    // for(auto it: mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
}


int main(){
    int arr[]={2,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    Map(arr,size);
    return 0;
}