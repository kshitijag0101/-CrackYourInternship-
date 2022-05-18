#include<bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k) {
    int rem=0,currsum=0,count=0;
    unordered_map<int,int> mp;
    mp[0]=1;
    for(int i=0;i<nums.size();i++){
        currsum+=nums[i];
        rem=currsum%k;
        if(rem<0){
            rem+=k;
        }
        if(mp.find(rem)!=mp.end()){
            count+=mp[rem];
        }
        mp[rem]+=1;
    }
    return count;
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
    int res=subarraysDivByK(nums,k);
    cout<<res<<endl;
}
