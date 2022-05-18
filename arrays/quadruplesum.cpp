#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> res;
    if(n<4) return res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int front=j+1,back=n-1;
            int target1=target-nums[i]-nums[j];
            while(front<back){
                int sum=nums[front]+nums[back];
                if(sum<target1){
                    front++;
                }
                else if(sum>target1){
                    back--;
                }
                else{
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[front]);
                    v.push_back(nums[back]);
                    res.push_back(v);
                    while(front<back && nums[front]==v[2]) front++;
                    while(front<back && nums[back]==v[3]) back--;
                }
            }
            while(j+1<n && nums[j+1]==nums[j]) j++;
        }
        while(i+1<n && nums[i+1]==nums[i]) i++;
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
    vector<vector<int>> res=fourSum(nums,target);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<3;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}