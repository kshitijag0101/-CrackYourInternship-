#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int res=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[res-1]){
            nums[res]=nums[i];
            res++;
        }
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
    int k=removeDuplicates(nums);
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
}