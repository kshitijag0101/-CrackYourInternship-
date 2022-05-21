#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>& nums,int * tmp,int low,int mid,int high){
    int count=0,i=low,j=mid+1;
    while(i<=mid){
        while(j<=high && (double(nums[i])/2)>double(nums[j])){
            j++;
        }
        count+=(j-mid-1);
        i++;
    }
    i=low;
    j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]){
            tmp[k]=nums[i];
            k++;
            i++;
        }
        else{
            tmp[k]=nums[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        tmp[k]=nums[i];
        i++;k++;
    }
    while(j<=high){
        tmp[k]=nums[j];
        j++;k++;
    }
    for(int i=low;i<=high;i++){
    nums[i]=tmp[i];  
    }
    return count;
}
int mergesort(vector<int>& nums,int* tmp,int low,int high){
    if(low>=high) return 0;
    int mid=(low+high)/2;
    int count=mergesort(nums,tmp,low,mid);
    count+=mergesort(nums,tmp,mid+1,high);
    count+=merge(nums,tmp,low,mid,high);
    return count;
}
int reversePairs(vector<int>& nums) {
    int tmp[nums.size()];
    int count=mergesort(nums,tmp,0,nums.size()-1);
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
    int res=reversePairs(nums);
    cout<<res<<endl;
}