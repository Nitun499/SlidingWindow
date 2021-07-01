#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
//Brute force approach
/*Time complexity =O(n^2) */
void NegativeNum(int * arr,int n,int k){
    for(int i=0;i<n-k+1;i++){               
        for(int j=0;j<k;j++){
            if(arr[i+j]<0){
                cout<<arr[i+j]<<" ";
                break;
            }
        }
    }
}
//Optimized approach 
vector<int> FirstNeg(int* arr,int n,int k){
    list<int> l;
    vector<int> ans(n-k+1);
    int i=0,j=0;
    while(j<n){
        //calculation
        if(arr[j]<0){
            l.push_back(arr[j]);
        }
        //approaching size of window
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            //finding answer from calculation
            if(l.size()==0){
                ans[i]=0;
            }else{
                ans[i]=l.front();
                if(l.front()==arr[i]){
                    l.pop_front();
                }  
            }
              i++,j++;  
        }
    }
    return ans;
}

int main(){
    int arr[]={3,-2,1,-7,5,-8,6};
    int size=sizeof(arr)/sizeof(arr[0]);
   vector<int> res=FirstNeg(arr,size,3);
   for(auto & a: res){
       cout<<a<<" ";
   }
    return 0;
}