#include<bits/stdc++.h>
using namespace std;
int missingNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int i=0;
    for(i=0;i<nums.size();i++){
        if(i!=nums[i]){
            return i;
        }
    }
    return i;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int res=missingNumber(nums);
    cout<<res<<endl;
}
