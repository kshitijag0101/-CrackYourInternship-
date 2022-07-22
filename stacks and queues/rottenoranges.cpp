#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    q.push({-1,-1});
    int ans=0;
    while(!q.empty()){
        bool flag=false;
        while(q.front().first!=-1){
            int i=q.front().first;
            int j=q.front().second;
            if((i-1)>=0 && grid[i-1][j]==1){
                if(!flag) ans++;
                flag=true;
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            if((j-1)>=0 && grid[i][j-1]==1){
                if(!flag) ans++;
                flag=true;
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            if((i+1)<n && grid[i+1][j]==1){
                if(!flag) ans++;
                flag=true;
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            if((j+1)<m && grid[i][j+1]==1){
                if(!flag) ans++;
                flag=true;
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            q.pop();
        }
        q.pop();
        if(!q.empty()){
            q.push({-1,-1});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int res=orangesRotting(grid);
    cout<<res<<endl;
}