#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    map<string,vector<string>> mp;
    for(int i=0;i<strs.size();i++){
        string s=strs[i];
        sort(s.begin(),s.end());
        mp[s].push_back(strs[i]);
    }
    for(auto x:mp){
        res.push_back(x.second);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<string> strs;
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        strs.push_back(x);
    }
    vector<vector<string>> res=groupAnagrams(strs);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}