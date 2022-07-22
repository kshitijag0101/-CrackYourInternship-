#include<bits/stdc++.h>
using namespace std;
string removeDuplicates(string s, int k) {
    deque<pair<char,int>> dq;
    dq.push_back({s[0],1});
    int i;
    for(i=1;i<s.length();){
        if(s[i]!=dq.back().first){
            dq.push_back({s[i],1});
        }
        else{
            dq.back().second+=1;
            if(dq.back().second==k){
            dq.pop_back();
            }
        }
        if(dq.empty() && i<s.length()-1){
            dq.push_back({s[i+1],1});
            i++;
        }
        i++;
    }
    string res="";
    while(!dq.empty()){
        for(int i=0;i<dq.front().second;i++){
            res+=dq.front().first;
        }
        dq.pop_front();
    }
    return res;
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    string res=removeDuplicates(s,k);
    cout<<res<<endl;
}