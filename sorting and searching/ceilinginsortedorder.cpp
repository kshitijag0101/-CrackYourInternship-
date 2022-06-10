#include<bits/stdc++.h>
using namespace std;
int ceilSearch(vector<int>& arr, int low, int high, int x){
    if(x==0){
        return -1;
    }
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    int index=ceilSearch(arr,0,n-1,x);
    if(index==-1){
        cout<<"Ceiling of "<<x<<" does not exist in an array";
    }
    else{
        cout<<"Ceiling of "<<x<<" is "<<arr[index];
    }
}