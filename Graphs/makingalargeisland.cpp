class Solution {
public:
    void giveid(int id,int i,int j,vector<vector<int>>& grid,int m,int n,int& count){
        if(i<0 || j<0 || i>=m ||j>=n) return;
        else if(grid[i][j]>1 || grid[i][j]==0) return;
        else{
            grid[i][j]=id;
            giveid(id,i+1,j,grid,m,n,count);
            giveid(id,i-1,j,grid,m,n,count);
            giveid(id,i,j+1,grid,m,n,count);
            giveid(id,i,j-1,grid,m,n,count);
            count++;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        map<int,int> mp;
        int id=2;
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count=0;
                    giveid(id,i,j,grid,m,n,count);
                    mp.insert({id,count});
                    id++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int sum=1;
                    set<int> s;
                    if(i-1>=0 && grid[i-1][j]>1 && s.find(grid[i-1][j])==s.end()){
                        s.insert(grid[i-1][j]);
                        auto it=mp.find(grid[i-1][j]);
                        sum+=it->second;
                    }
                    if(i+1<m && grid[i+1][j]>1 && s.find(grid[i+1][j])==s.end()){
                        s.insert(grid[i+1][j]);
                        auto it=mp.find(grid[i+1][j]);
                        sum+=it->second;
                    }
                    if(j-1>=0 && grid[i][j-1]>1 && s.find(grid[i][j-1])==s.end()){
                        s.insert(grid[i][j-1]);
                        auto it=mp.find(grid[i][j-1]);
                        sum+=it->second;
                    }
                    if(j+1<n && grid[i][j+1]>1 && s.find(grid[i][j+1])==s.end()){
                        s.insert(grid[i][j+1]);
                        auto it=mp.find(grid[i][j+1]);
                        sum+=it->second;
                    }
                    maxi=max(maxi,sum);
                }
            }
        }
        return (maxi==INT_MIN)?m*n:maxi;
    }
};