#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    string s=to_string(x);
    string str=string(s.rbegin(),s.rend());
    if(str!=s){
        return false;
    }
    return true;
}
int main(){
    int x;
    cin>>x;
    bool res=isPalindrome(x);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}
