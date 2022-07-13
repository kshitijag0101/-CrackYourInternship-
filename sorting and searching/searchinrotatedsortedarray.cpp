#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int low=0,high=nums.size()-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        if(nums[low]<=nums[mid]){
            if(target>=nums[low] && target<nums[mid]) high=mid-1;
            else low=mid+1;
        }
        else{
            if(target>nums[mid] && target<=nums[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n,target;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>target;
    int res=search(nums,target);
    cout<<res<<endl;
}