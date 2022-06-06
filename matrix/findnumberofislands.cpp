#include<bits/stdc++.h>
using namespace std;
int isSafe(vector<vector<int>>& m,int row,int col,vector<vector<bool>>& visited){
    return((row>=0) && (row<m.size()) && (col>=0) && (col<m[0].size()) && (m[row][col] && !visited[row][col]));
}
void DFS(vector<vector<int>>& m,int row,int col,vector<vector<bool>>& visited){
    int ro[]={-1,-1,-1,0,0,1,1,1};
    int co[]={-1,0,1,-1,1,-1,0,1};
    visited[row][col]=true;
    for(int k=0;k<8;k++){
        if(isSafe(m,row+ro[k],col+co[k],visited)){
            DFS(m,row+ro[k],col+co[k],visited);
        }
    }
}
int countislands(vector<vector<int>>& m,int r,int c){
    vector<vector<bool>> visited(r,vector<bool>(c,0));
    int count=0;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if (m[i][j] && !visited[i][j]){
                DFS(m,i,j,visited);
                count++;
            }
        }
    }
    return count;
}
int main(){
    int r,c,x;
    cin>>r>>c;
    vector<vector<int>> m;
    for(int i=0;i<r;i++){
        vector<int> b;
        for(int j=0;j<c;j++){
            cin>>x;
            b.push_back(x);
        }
        m.push_back(b);
    }
    int res=countislands(m,r,c);
    cout<<"No of islands = "<<res<<endl;
}