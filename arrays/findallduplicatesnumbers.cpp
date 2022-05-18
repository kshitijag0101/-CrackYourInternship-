#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    unordered_set<int> s;
    s.insert(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(s.find(nums[i])!=s.end()){
            res.push_back(nums[i]);
        }
        else{
            s.insert(nums[i]);
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
    vector<int> res=findDuplicates(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}