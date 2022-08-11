class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n=grid.size(),m=grid[0].size();
        int dirx[4]={1,-1,0,0};
        int diry[4]={0,0,-1,1};
        int res=0;
        pq.push({grid[0][0],{0,0}});
        grid[0][0]=-1;
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                int val=pq.top().first;
                int x=pq.top().second.first;
                int y=pq.top().second.second;
                pq.pop();
                res=max(res,val);
                if(x==n-1 && y==m-1) return res;
                for(int i=0;i<4;i++){
                    int nx=x+dirx[i];
                    int ny=y+diry[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]==-1) continue;
                    pq.push({grid[nx][ny],{nx,ny}});
                    grid[nx][ny]=-1;
                }
            }
        }
        return res;
    }
};