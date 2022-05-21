#include <bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle) {
    int d=10,h=1,q=23,m=needle.length(),n=haystack.length();
    for(int i=1;i<=m-1;i++){
        h=(h*d)%q;
    }
    int p=0,t=0;
    for(int i=0;i<m;i++){
        p=(p*d+needle[i])%q;
        t=(t*d+haystack[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(p==t){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(haystack[i+j]!=needle[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                return i;
            }
        }
        if(i<n-m){
            t=(d*(t-haystack[i]*h)+haystack[i+m])%q;
            if(t<0) t=t+q;
        }
    }
    return -1;
}
int main(){
    string haystack,needle;
    cin>>haystack>>needle;
    int res=strStr(haystack,needle);
    cout<<res<<endl;
}