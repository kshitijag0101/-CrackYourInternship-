#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size()<3){
        return res;
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++){
        if(i==0 || nums[i]>nums[i-1]){
            int start=i+1,end=nums.size()-1;
            int target=-nums[i];
            while(start<end){
                if(start>i+1 && nums[start]==nums[start-1]){
                    start++;
                    continue;
                }
                if(end<nums.size()-1 && nums[end]==nums[end+1]){
                    end--;
                    continue;
                }
                if(target==(nums[start]+nums[end])){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[start]);
                    v.push_back(nums[end]);
                    res.push_back(v);
                    start++;
                    end--;
                }
                else if(target>(nums[start]+nums[end])){
                    start++;
                }
                else{
                    end--;
                }
            }
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
    vector<vector<int>> res=threeSum(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<3;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}