#include<bits/stdc++.h>
using namespace std;
string addBinary(string a, string b) {
    int i=a.length()-1,j=b.length()-1,carry=0;
    string ans="";
    while(i>=0 || j>=0){
        int sum=carry;
        if(i>=0){
            sum+=a[i]-'0';
            i--;
        }
        if(j>=0){
            sum+=b[j]-'0';
            j--;
        }
        carry=sum>1?1:0;
        ans+=to_string(sum%2);
    }
    if(carry){
        ans+=to_string(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string a,b;
    cin>>a>>b;
    string res=addBinary(a,b);
    cout<<res<<endl;
}