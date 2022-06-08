#include<bits/stdc++.h>
using namespace std;
string convertToTitle(int columnNumber) {
    string res="";
    int n=columnNumber;
    while(n){
        char ans='A'+(n-1)%26;
        res=ans+res;
        n=(n-1)/26;
    }
    return res;
}
int main(){
    int columnNumber;
    cin>>columnNumber;
    string res=convertToTitle(columnNumber);
    cout<<res<<endl;
}
