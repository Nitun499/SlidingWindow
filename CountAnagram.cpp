#include<bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
using namespace std;
//Simple approach for counting number of anagram
bool IsAnagram(string s1,string s2){
    unordered_map<char,int> mp;
    for(int i=0;i<s1.length();i++){
        mp[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        mp[s2[i]]--;
    }
    for(auto it=mp.begin(); it!=mp.end();it++){
        if(it->second!=0){
            return false;
        }  
    }
     return true;
}
int CountAnagra(string s1,string s2){
    int ans=0;
    for(int i=0;i<s1.length()-s2.length()+1;i++){
        if(IsAnagram(s1.substr(i,s2.length()),s2)){
        //    cout<<s1.substr(i,s2.length())<<" "; ->For printing substring or u can say all anagram of a string
           ans++;
        }
    }
    return ans;
}

//Optimized ->Less comaprision(Sliding Window)
int Solve(string s1,string s2){
    unordered_map<char,int> mp;
    for(int i=0;i<s2.length();i++){
        mp[s2[i]]++;
    }
    int count=mp.size();
    int ans=0;
    int i=0,j=0;
    while(j<s1.length()){
        //calculation as we move j pointer
        if(mp.find(s1[j])!=mp.end()){
            mp[s1[j]]--;
            if(mp[s1[j]]==0)
                count--;
        }
        //checking length of substring each time (it must be equal to pattern string in length .If not then increase j pointer)
        if(j-i+1<s2.length()){
            j++;
        }
        //when we hit the size of substring equal to pattern string then we find answer
        else if(j-i+1==s2.length()){
            //if count becomes zero -> all the character of current substring is equal to pattern string.
            if(count==0){ans++;}
            //increase count 
                
            //sliding window ->by checking if current character at i index is in our pattern string if yes then simply update the
            //frequency in map
            if(mp.find(s1[i])!=mp.end()){
                mp[s1[i]]++;
                if(mp[s1[i]]==1)
                    count++;
            }
            //sliding window
            i++;
            j++;
        }
    }
    
    
    return ans;
}


int main(){
    string text="kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk";
    string ptr="kkkkk";
    // int res=CountAnagra(text,ptr);
    int res2=Solve(text,ptr);
    cout<<res2;
   
    return 0;
}