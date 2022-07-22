#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    map<int,int> mp;
    stack<int> st;
    for(int i=nums2.size()-1;i>=0;i--){
        while(st.empty()==false && st.top()<=nums2[i]){
            st.pop();
        }
        if(st.empty()){
            mp[nums2[i]]=-1;
        }
        else{
            mp[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    for(int x: nums1){
        res.push_back(mp[x]);
    }
    return res;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n),nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    vector<int> res=nextGreaterElement(nums1,nums2);
    for(int x: res){
        cout<<x<<" ";
    }
}