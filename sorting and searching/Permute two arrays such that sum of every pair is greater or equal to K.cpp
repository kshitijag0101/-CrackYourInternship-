#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>& a,vector<int>& b,int k){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<a.size();i++){
        if(a[i]+b[i]<k){
            return false;
        }
    }
    return true;
}
int main(){
    int n,k;
    cin>>n;
    vector<int> a(n,0),b(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    cin>>k;
    bool res=isPossible(a,b,k);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}
