#include<bits/stdc++.h>
using namespace std;
void combinationUtil(vector<int>& arr,int data[],int start,int end,int index,int r){
    if(index==r){
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }
    for(int i = start; i <= end && end - i + 1 >= r - index; i++){
        data[index] = arr[i];
        combinationUtil(arr,data,i+1,end,index+1,r);
    }
}
void printCombination(vector<int>& arr, int n, int r){
    int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}
int main(){
    int n,x;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int r;
    cin>>r;
    printCombination(arr, n, r);
}