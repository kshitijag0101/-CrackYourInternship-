#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        if(mp.find(target-nums[i])!=mp.end()){
            res.push_back(mp[target-nums[i]]);
            res.push_back(i);
            return res;
        }
        mp[nums[i]]=i;
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
    int target;
    cin>>target;
    vector<int> res=twoSum(nums,target);
    cout<<res[0]<<" "<<res[1]<<endl;
}
