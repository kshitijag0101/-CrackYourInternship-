#include<bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int sum=0,res=0;
    mp[sum]=1;
    for(auto x:nums){
        sum+=x;
        if(mp.find(sum-k)!=mp.end()){
            res+=mp[sum-k];
        }
        mp[sum]++;
    }
    return res;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int k;
    cin>>k;
    int res=subarraySum(nums,k);
    cout<<res<<endl;
}