class Solution {
public:
    vector<int> findrc(int curr,int n){
        vector<int> res;
        int r=n-(curr-1)/n-1;
        res.push_back(r);
        int c=(curr-1)%n;
        if(r%2==n%2){
            res.push_back(n-1-c);
        }
        else{
            res.push_back(c);
        }
        return res;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int steps=0;
        vector<vector<int>> visited(n, vector<int>(n));
        queue<int> q;
        q.push(1);
        visited[n-1][0]=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front();
                q.pop();
                if(x==n*n) return steps;
                for(int k=1;k<7;k++){
                    if(k+x>n*n) break;
                    vector<int> pos=findrc(k+x,n);
                    int r=pos[0],c=pos[1];
                    if(visited[r][c]==1) continue;
                    visited[r][c]=1;
                    if(board[r][c]==-1){
                        q.push(k+x);
                    }
                    else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};