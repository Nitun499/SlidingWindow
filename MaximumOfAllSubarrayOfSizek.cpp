#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
vector<int> Maximumofsubarray(vector<int>&arr,int k){
    //use two pointer approach
    int i=0,j=0;
    list<int>l;
    vector<int>ans;
    while(j<arr.size()){
        //do calculatio ,like pop all the elements that are smaller than current element wheere j i 
        //pointing now until elements are smaller and size of list is not empty
        while(l.back()<arr[j]&& l.size()!=0){
            l.pop_back();
        }
        //push current element into list
        l.push_back(arr[j]);
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            //find the answer from curent window
            ans.push_back(l.front());
            //slide the window
            if(l.front()==arr[i]){
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={0,-1,-2,3,-6,5,7,6,-11};
    vector<int>res=Maximumofsubarray(arr,4);
    for(auto it :res){
        cout<<it<<" ";
    }
    return 0;
}