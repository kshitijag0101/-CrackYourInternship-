// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string smallestWindow (string s, string p){
        unordered_map<char,int> mp;
        for(int i=0;i<p.length();i++){
            mp[p[i]]++;
        }
        int i=0,j=0,mini=INT_MAX,start=0;
        int count=mp.size();
        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
            if(count==0){
                while(count==0){
                    if(mini>j-i+1){
                        mini=min(mini,j-i+1);
                        start=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(mini==INT_MAX){
            return "-1";
        }
        else{
            return s.substr(start,mini);
        }
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  