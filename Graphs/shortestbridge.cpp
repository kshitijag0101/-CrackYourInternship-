class Solution {
public:
    void floodFill(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>>& res){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        res.push_back(make_pair(i,j));
        floodFill(grid,i+1,j,res);
        floodFill(grid,i-1,j,res);
        floodFill(grid,i,j+1,res);
        floodFill(grid,i,j-1,res);
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>> x;
        vector<pair<int,int>> y;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                    if(count==1){
                        floodFill(grid,i,j,x);
                    }
                    else if(count==2){
                        floodFill(grid,i,j,y);
                    }
                }
            }
        }
        int minDist=INT_MAX;
        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
                int dist=abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1;
                minDist=min(minDist,dist);
            }
        }
        return minDist;
    }
};