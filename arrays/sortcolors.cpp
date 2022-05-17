#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    sortColors(nums);
}