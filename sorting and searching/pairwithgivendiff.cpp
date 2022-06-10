#include<bits/stdc++.h>
using namespace std;
bool findPair(vector<int>& arr,int sum){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
        if(sum==0 && mp[arr[i]]>1){
            cout<<"Pair is:- "<<arr[i]<<" "<<arr[i]<<endl;
            return true;
        } 
    }
    if(sum==0) return false;
    for(int i=0;i<arr.size();i++){
        if(mp.find(sum+arr[i])!=mp.end()){
            cout<<"Pair is:- "<<arr[i]<<" "<<sum+arr[i]<<endl;
            return true;
        }
    }
    cout<<"No Pair found";
    return false;
}
int main(){
    int n,sum;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>sum;
    findPair(arr,sum);
}