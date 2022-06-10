#include<bits/stdc++.h>
using namespace std;
int getMax(vector<int>& arr){
    int mx=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>mx) mx=arr[i];
    }
    return mx;
}
void countsort(vector<int>& arr,int exp){
    int output[arr.size()],count[10]={0};
    for(int i=0;i<arr.size();i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=arr.size()-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=output[i];
    }
}
void radixsort(vector<int>& arr){
    int m=getMax(arr);
    for(int exp=1;m/exp>0;exp*=10){
        countsort(arr,exp);
    }
}
int main(){
    int n,sum;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    radixsort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}