#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    unordered_map<char,int> mp;
    for(int i=0;i<t.length();i++){
        mp[t[i]]++;
    }
    int i=0,j=0,mini=INT_MAX,start=0;
    int count=mp.size();
    while(j<s.size()){
        mp[s[j]]--;
        if(mp[s[j]]==0){
            count--;
        }
        if(count==0){
            while(count==0){
                if(mini>j-i+1){
                    mini=min(mini,j-i+1);
                    start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count++;
                }
                i++;
            }
        }
        j++;
    }
    if(mini==INT_MAX){
        return "";
    }
    else{
        return s.substr(start,mini);
    }
}
int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    string res=minWindow(s,t);
    cout<<res<<endl;
}  