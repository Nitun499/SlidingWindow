#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
//Brute force->O(n^2)
int MaxSum(int* arr,int n,int k){
    int max_sum=INT_MIN;
    for(int i=0;i<n-k+1;i++){
        int curr_sum=0;
        for(int j=0;j<k;j++){
            curr_sum+=arr[i+j];
        }
        max_sum=max(max_sum,curr_sum);
    }
    return max_sum;
}
//Optimized->O(n)
int MaxSum2(int* arr,int n,int k){
    int i=0,j=0;
    int curr_sum=0,max_sum=INT_MIN;
    while(j<n){
        //calculation
        curr_sum+=arr[j];
        //approaching window size
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            //finding ans through calculation
            max_sum=max(curr_sum,max_sum);
            curr_sum=curr_sum-arr[i];
            //moving window
            i++,j++;
        }
    }
    return max_sum;
}

int main(){
    int arr[]={100,200,300,400};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<MaxSum2(arr,size,2);

    return 0;
}