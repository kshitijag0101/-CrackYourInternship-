#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
    string res="";
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string s1="";
        while(i<s.length() && s[i]!=' '){
            s1+=s[i];
            i++;
        }
        if(s1=="") continue;
        st.push(s1);
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
        res+=" ";
    }
    res.pop_back();
    return res;
}
int main(){
    string s;
    getline(cin,s);
    string res=reverseWords(s);
    cout<<res<<endl;
}