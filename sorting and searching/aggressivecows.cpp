#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& arr,int c,int num){
    int cows=1,prev=arr[0];
    for(int i=1;i<arr.size();i++){
        if((arr[i]-prev)>=num){
            cows++;
            prev=arr[i];
        }
    }
    if(cows>=c) return true;
    return false;
}
int bs(vector<int>& arr,int c,int low,int high){
    int mx=-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(arr,c,mid)){
            mx=max(mx,mid);
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return mx;
}
int main(){
    int n,c;
    cin>>n>>c;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int res=bs(arr,c,0,arr[n-1]);
    cout<<res<<endl;
}