#include<bits/stdc++.h>
using namespace std;
string intToRoman(int num) {
    map<int,string,greater<int>> mp;
    mp[1]="I";
    mp[5]="V";
    mp[10]="X";
    mp[50]="L";
    mp[100]="C";
    mp[500]="D";
    mp[1000]="M";
    mp[4]="IV";
    mp[9]="IX";
    mp[40]="XL";
    mp[90]="XC";
    mp[400]="CD";
    mp[900]="CM";
    string res="";
    while(num!=0){
        for(auto it:mp){
            if(num>=it.first){
                res+=it.second;
                num-=it.first;
                break;
            }
        }
    }
    return res;
}
int main(){
    int num;
    cin>>num;
    string res=intToRoman(num);
    cout<<res<<endl;
}