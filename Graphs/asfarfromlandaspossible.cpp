class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        int ans=-1;
        while(!q.empty()){
            ans++;
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx<0 || newy<0 || newx>=n || newy>=m || grid[newx][newy]==1) continue;
                    q.push({newx,newy});
                    grid[newx][newy]=1;
                }
            }
        }
        return ans==0?-1:ans;
    }
};