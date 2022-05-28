#include<bits/stdc++.h>
using namespace std;
int calculate(string s) {
    int n=s.length();
    stack<int> st;
    char sign='+';
    for(int i=0;i<n;i++){
        if(s[i]==' ') continue;
        if(isdigit(s[i])){
            int val=0;
            while (i<n && isdigit(s[i])){
                val=10*val+(s[i]-'0');
                i++;
            }
            i--;
            if(sign=='+'){
                st.push(val);
            }
            else if(sign=='-'){
                st.push(-val);
            }
            else if(sign=='*'){
                int top=st.top();
                st.pop();
                st.push(val*top);
            }
            else if(sign=='/'){
                int top=st.top();
                st.pop();
                st.push(top/val);
            }
        }
        else if(s[i]!=' '){
            sign=s[i];
        }
    }
    int res=0;
    while(!st.empty()){
        int t=st.top();
        res+=t;
        st.pop();
    }
    return res;
}
int main(){
    string s;
    getline(cin,s);
    int res=calculate(s);
    cout<<res<<endl;
}