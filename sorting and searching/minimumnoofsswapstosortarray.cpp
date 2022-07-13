#include<bits/stdc++.h>
using namespace std;
int minSwaps(int arr[],int n){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]=i;
    }
    sort(arr,arr+n);
    bool visited[n]={0};
    int res=0;
    for(int i=0;i<n;i++){
        if(visited[i] || mp[arr[i]]==i) continue;
        int j=i,cycle=0;
        while(!visited[j]){
            visited[j]=true;
            j=mp[arr[j]];
            cycle++;
        }
        if(cycle>0){
            res+=(cycle-1);
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=minSwaps(arr,n);
    cout<<res<<endl;
}