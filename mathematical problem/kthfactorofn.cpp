#include<bits/stdc++.h>
using namespace std;
int kthFactor(int n, int k) {
    int i=1;
    for(i=1;i*i<=n;i++){
        if(n%i==0 && --k==0){
            return i;
        }
    }
    for(i=i-1;i>=1;i--){
        if(i*i==n) continue;
        if(n%i==0 && --k==0){
            return n/i;
        }
    }
    return -1;
}
int main(){
    int n,k;
    cin>>n>>k;
    int res=kthFactor(n,k);
    cout<<res<<endl;
}