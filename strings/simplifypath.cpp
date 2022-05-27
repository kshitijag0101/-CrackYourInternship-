#include<bits/stdc++.h>
using namespace std;
string simplifyPath(string path) {
    stack<string> st;
    string res;
    for(int i=0;i<path.length();i++){
        if(path[i]=='/'){
            continue;
        }
        string tmp;
        while(i<path.length() && path[i]!='/'){
            tmp+=path[i];
            i++;
        }
        if(tmp=="."){
            continue;
        }
        else if(tmp==".."){
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            st.push(tmp);
        }
    }
    while(!st.empty()){
        res="/"+st.top()+res;
        st.pop();
    }
    if(res.length()==0){
        return "/";
    }
    return res;
}
int main(){
    string path;
    cin>>path;
    string res=simplifyPath(path);
    cout<<res<<endl;
}