#include<bits/stdc++.h>
using namespace std;
bool isNumber(string s) {
    bool digit=false,e=false,dot=false;
    int countsign=0;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(isdigit(ch)){
            digit=true;
        }
        else if(ch=='+' || ch=='-'){
            if(countsign==2){
                return false;
            }
            if(i>0 && (s[i-1]!='e' && s[i-1]!='E')){
                return false;
            }
            if(i==s.length()-1){
                return false;
            }
            countsign++;
        }
        else if(ch=='.'){
            if(e || dot){
                return false;
            }
            if(i==s.length()-1 && !digit){
                return false;
            }
            dot=true;
        }
        else if(ch=='e' || ch=='E'){
            if(e || !digit || i==s.length()-1){
                return false;
            }
            e=true;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    bool res=isNumber(s);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}