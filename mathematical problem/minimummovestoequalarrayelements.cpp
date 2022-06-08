#include<bits/stdc++.h>
using namespace std;
int minMoves(vector<int>& nums) {
    int count=0;
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i++){
        count+=(nums[i]-nums[0]);
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int res=minMoves(nums);
    cout<<res<<endl;
}
