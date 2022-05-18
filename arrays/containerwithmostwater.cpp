#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int l=0,r=height.size()-1;
    int res=0;
    while(l<r){
        res=max(res,(min(height[l],height[r])*(r-l)));
        if(height[l]>height[r]){
            r--;
        }
        else{
            l++;
        }       
    }
    return res;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> height;
    for(int i=0;i<n;i++){
        cin>>x;
        height.push_back(x);
    }
    int m;
    cin>>m;
    int res=maxArea(height);
    cout<<res<<" ";
}
