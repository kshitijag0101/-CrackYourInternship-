#include<bits/stdc++.h>
using namespace std;
int findmindiff(vector<int>& nums,int m){
    if(m==0){
        return 0;
    }
    if(m>nums.size()){
        return -1;
    }
    sort(nums.begin(),nums.end());
    int mindiff=INT_MAX;
    for(int i=0;i+m-1<nums.size();i++){
        int diff=nums[i+m-1]-nums[i];
        if(diff<mindiff) mindiff=diff;
    }
    return mindiff;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int m;
    cin>>m;
    int res=findmindiff(nums,m);
    cout<<res<<" ";
}
