#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums) {
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(i>index) return false;
            index=max(index,i+nums[i]);
        }
        return true;
    }
int main(){
    int n,x;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    bool res=canJump(nums);
    if(res) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
}