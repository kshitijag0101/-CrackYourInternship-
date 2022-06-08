#include<bits/stdc++.h>
using namespace std;
int maximumProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int res1=nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
    int res2=nums[0]*nums[1]*nums[nums.size()-1];
    return max(res1,res2);
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int res=maximumProduct(nums);
    cout<<res<<endl;
}
