#include<bits/stdc++.h>
using namespace std;
bool isfeasible(int A[],int N,int M,int ans){
    int res=1,sum=0;
    for(int i=0;i<N;i++){
        if(sum+A[i]>ans){
            res++;
            sum=A[i];
        }
        else{
            sum+=A[i];
        }
    }
    return res<=M;
}
int findPages(int A[], int N, int M) {
    int sum=0,mx=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
        mx=max(mx,A[i]);
    }
    int low=mx,high=sum,mid,res;
    while(low<=high){
        mid=(low+high)/2;
        if(isfeasible(A,N,M,mid)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int main(){
    int N,M;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cin>>M;
    int res=findPages(A,N,M);
    cout<<res<<endl;
}