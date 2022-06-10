#include<bits/stdc++.h>
using namespace std;
bool checkReverse(vector<int>& arr){
    vector<int> temp=arr;
    sort(temp.begin(),temp.end());
    int front,back;
    for(front=0;front<arr.size();front++){
        if(temp[front]!=arr[front]) break;
    }
    for(back=arr.size()-1;back>=0;back--){
        if(temp[back]!=arr[back]) break;
    }
    if(front>=back) return true;
    do{
        front++;
        if(arr[front-1]<arr[front]) return false;
    }while(front!=back);
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool res=checkReverse(arr);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}