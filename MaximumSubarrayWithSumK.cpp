#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
// brute force approach O(n^2)
// question is to return length of largest subarray with sum k or also print that subarray
pair<int,int> LargestSubarrayWithSumK(int* arr,int n,int k){
    int maxlen=0,curr_sum=0;
    pair<int,int> p;
    for(int i=0;i<n-1;i++){
        curr_sum=arr[i];
        for(int j=i+1;j<n;j++){
            curr_sum+=arr[j];
            if(curr_sum==k && j-i+1>maxlen){
                maxlen=j-i+1;
                p={i,j};
                break;
            }
        }
    }
    return p;
}


int main(){
    int arr[]={-5, 8, -14, 2, 4, 12 };
    int k=-5;
    auto  ans=LargestSubarrayWithSumK(arr,6,k);
    int first=ans.first;
    int second=ans.second;
    for(int i=first;i<=second;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}