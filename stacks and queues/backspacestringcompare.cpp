#include<bits/stdc++.h>
using namespace std;
bool backspaceCompare(string s, string t) {
    string str1="",str2="";
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='a' && s[i]<='z') str1+=s[i];
        else if(str1.empty()==false) str1.pop_back();
        i++;
    }
    i=0;
    while(t[i]!='\0'){
        if(t[i]>='a' && t[i]<='z') str2+=t[i];
        else if(str2.empty()==false) str2.pop_back();
        i++;
    }
    if(str1==str2){
        return true;
    }
    return false;
}
int main(){
    string s,t;
    cin>>s>>t;
    bool res=backspaceCompare(s,t);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}