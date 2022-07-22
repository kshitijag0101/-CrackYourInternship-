#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>nearest(vector<vector<int>>grid){
    vector<vector<int>> res(grid.size(),vector<int>(grid[0].size(),INT_MAX));
    queue<pair<int,int>> q;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                res[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        if((i-1)>=0 && res[i][j]+1<res[i-1][j]){
            res[i-1][j]=res[i][j]+1;
            q.push({i-1,j});
        }
        if((j-1)>=0 && res[i][j]+1<res[i][j-1]){
            res[i][j-1]=res[i][j]+1;
            q.push({i,j-1});
        }
        if((i+1)<grid.size() && res[i][j]+1<res[i+1][j]){
            res[i+1][j]=res[i][j]+1;
            q.push({i+1,j});
        }
        if((j+1)<grid[0].size() && res[i][j]+1<res[i][j+1]){
            res[i][j+1]=res[i][j]+1;
            q.push({i,j+1});
        }
        q.pop();
    }
    return res;
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> grid(r,vector<int>(c,0)); 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> res=nearest(grid);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}