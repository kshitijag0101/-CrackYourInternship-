#include<bits/stdc++.h>
using namespace std;
void productArray(vector<int>& arr){
    if(arr.size()==1){
        cout<<0;
        return;
    }
    int temp=1;
    int product[arr.size()]={1};
    for(int i=0;i<arr.size();i++){
        product[i]=temp;
        temp*=arr[i];
    }
    temp=1;
    for(int i=arr.size()-1;i>=0;i--){
        product[i]*=temp;
        temp*=arr[i];
    }
    for(int i=0;i<arr.size();i++){
        cout<<product[i]<<" ";
    }
}
int main(){
    int n,sum;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    productArray(arr);
}