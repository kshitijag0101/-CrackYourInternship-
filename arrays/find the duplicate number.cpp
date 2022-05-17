#include<bits/stdc++.h>
using namespace std;
int dup_num(vector<int>& nums,int n){
    while(nums[0]!=nums[nums[0]]){
        swap(nums[0],nums[nums[0]]);
    }
    return nums[0];
}
int main(){
    int n,x;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<=n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int res=dup_num(nums,n);
    cout<<res<<endl;
}