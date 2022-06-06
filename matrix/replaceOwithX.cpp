#include<bits/stdc++.h>
using namespace std;
void floodfill(vector<vector<char>>& mat,int i,int j,char prev,char next){
    if(i<0 || i>mat.size()-1 || j<0 || j>mat[0].size()-1) return;
    if(mat[i][j]!=prev) return;
    mat[i][j]=next;
    floodfill(mat,i+1,j,prev,next);
    floodfill(mat,i-1,j,prev,next);
    floodfill(mat,i,j+1,prev,next);
    floodfill(mat,i,j-1,prev,next);
}
void replacesurrounded(vector<vector<char>>& mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]=='O') mat[i][j]='-';
        }
    }
    for(int i=0;i<mat.size();i++){
        if(mat[i][0]=='-')
            floodfill(mat,i,0,'-','O');
    }
    for(int i=0;i<mat.size();i++){
        if(mat[i][mat[0].size()-1]=='-')
            floodfill(mat,i,mat[0].size()-1,'-','O');
    }
    for(int i=0;i<mat[0].size();i++){
        if(mat[0][i]=='-')
            floodfill(mat,0,i,'-','O');
    }
    for(int i=0;i<mat[0].size();i++){
        if(mat[mat.size()-1][i]=='-')
            floodfill(mat,mat.size()-1,i,'-','O');
    }
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]=='-') mat[i][j]='X';
        }
    }
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<char>> mat(r,vector<char>(c,0)); 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    replacesurrounded(mat);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}