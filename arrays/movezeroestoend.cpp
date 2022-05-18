#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[count]);
            count++;
        }
    }
}
int main(){
    int n,x;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    moveZeroes(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}
