#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    bool iscol=false;
    int r=matrix.size();
    int c=matrix[0].size();
    for(int i=0;i<r;i++){
        if(matrix[i][0]==0){
            iscol=true;
        }
        for(int j=1;j<c;j++){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=0;j<c;j++){
            matrix[0][j]=0;
        }
    }
    if(iscol){
        for(int i=0;i<r;i++){
            matrix[i][0]=0;
        }
    }
}
int main(){
    int r,c,x;
    cin>>r>>c;
    vector<vector<int>> matrix;
    for(int i=0;i<r;i++){
        vector<int> mat;
        for(int j=0;j<c;j++){
            cin>>x;
            mat.push_back(x);
        }
        matrix.push_back(mat);
    }
    setZeroes(matrix);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}