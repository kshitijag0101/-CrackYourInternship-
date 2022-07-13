#include<bits/stdc++.h>
using namespace std;
int minCostToMakeElementEqual(vector<int>& arr){
    int y,n=arr.size();
    if(n%2==1){
        y=arr[n/2];
    }
    else{
        y=((arr[n/2])+arr[(n-2)/2])/2;
    }
    int count=0;
    for(int i=0;i<n;i++){
        count+=abs(arr[i]-y);
    }
    return count;
}
int main(){
    int n,sum;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=minCostToMakeElementEqual(arr);
    cout<<res<<endl;
}