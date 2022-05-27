#include<bits/stdc++.h>
using namespace std;
void generate(vector<string>& res,int open,int close,string s){
    if(open==0 && close==0){
        res.push_back(s);
    }
    if(open!=0){
        string s1=s;
        s1+='(';
        generate(res,open-1,close,s1);
    }
    if(close>open){
        string s2=s;
        s2+=')';
        generate(res,open,close-1,s2);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    int open=n,close=n;
    generate(res,open,close,"");
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string> res=generateParenthesis(n);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}