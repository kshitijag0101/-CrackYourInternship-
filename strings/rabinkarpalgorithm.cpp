#include <bits/stdc++.h>
using namespace std;
int strStr(string text, string pat) {
    int d=256,h=1,q=101,m=pat.length(),n=text.length();
    for(int i=1;i<=m-1;i++){
        h=(h*d)%q;
    }
    int p=0,t=0;
    for(int i=0;i<m;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+text[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(p==t){
            bool flag=true;
            for(int j=0;j<m;j++){
                if(text[i+j]!=pat[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                return i;
            }
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0) t=t+q;
        }
    }
    return -1;
}
int main(){
    string text,pat;
    getline(cin,text);
    getline(cin,pat);
    int res=strStr(text,pat);
    cout<<res<<endl;
}