#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> res;
    int i=0,j=0;
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            res.push_back(nums1[i]);
            i++;
        }
        else{
            res.push_back(nums2[j]);
            j++;
        }
    }
    while(i<m){
        res.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        res.push_back(nums2[j]);
        j++;
    }
    for(int i=0;i<res.size();i++){
        nums1[i]=res[i];
    }
}
int main(){
    int n,m;
    cin>>m>>n;
    vector<int> nums1(m+n,0),nums2(n,0);
    for(int i=0;i<m;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<n;i++){
        cin>>nums2[i];
    }
    merge(nums1,m,nums2,n);
    for(int i=0;i<n+m;i++){
        cout<<nums1[i]<<" ";
    }
}
