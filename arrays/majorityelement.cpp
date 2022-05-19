#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
    int res=0,count=1;
    for(int i=1;i<nums.size();i++){
        if(nums[res]==nums[i]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            res=i;
            count=1;
        }
    }
    return nums[res];
}
int main(){
    int n,x;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<=n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int res=majorityElement(nums);
    cout<<res<<endl;
}