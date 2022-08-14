class Solution {
public:
    int pathbox=1;
    int solve(vector<vector<int>>& grid,int r,int c,int count){
        if(r>=grid.size() || c>=grid[0].size() || r<0 || c<0) return 0;
        if(grid[r][c]==2){
            if(count==pathbox) return 1;
            else return 0;
        }
        if(grid[r][c]!=0) return 0;
        grid[r][c]=3;
        int res=solve(grid,r+1,c,count+1)+solve(grid,r-1,c,count+1)+solve(grid,r,c+1,count+1)+solve(grid,r,c-1,count+1);
        grid[r][c]=0;
        return res;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int> start;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) start={i,j};
                if(grid[i][j]==0) pathbox++;
            }
        }
        grid[start.first][start.second]=0;
        return solve(grid,start.first,start.second,0);
    }
};