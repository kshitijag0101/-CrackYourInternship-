#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) {
    if(n==1 || n==2){
        return true;
    }
    if(n%2!=0 || n==0){
        return false;
    }
    return isPowerOfTwo(n/2);
}
int main(){
    int n;
    cin>>n;
    bool res=isPowerOfTwo(n);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}