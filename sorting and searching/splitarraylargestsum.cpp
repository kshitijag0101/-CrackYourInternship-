#include<bits/stdc++.h>
using namespace std;
bool splitcheck(vector<int>& nums,int mid,int& m){
    int sum=0,sum_curr=0;
    for(int i=0;i<nums.size();i++){
        sum_curr+=nums[i];
        if(sum_curr>mid){
            sum+=1;
            sum_curr=nums[i];
        }
    }
    return (sum+1<=m);
}
int splitArray(vector<int>& nums, int m) {
    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);
    int res=high;
    while(low<=high){
        int mid=(low+high)/2;
        if(splitcheck(nums,mid,m)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int main(){
    int n,m;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>m;
    int res=splitArray(nums,m);
    cout<<res<<endl;
}