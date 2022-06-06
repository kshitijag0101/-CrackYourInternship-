#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        int low=0,high=n-1;
        while(low<high){
            swap(matrix[i][low],matrix[i][high]);
            low++;
            high--;
        }
        
    }
}
int main(){
    int r,c,x;
    cin>>r>>c;
    vector<vector<int>> matrix(r,vector<int>(c,0)); 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
        }
    }
    rotate(matrix);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}