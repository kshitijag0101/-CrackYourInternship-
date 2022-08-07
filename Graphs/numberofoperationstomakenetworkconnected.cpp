class Solution {
public:
    void BFS(vector<vector<int>>& adj, int s, vector<bool>& visited){
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int x:adj[u]){
                if(visited[x] == false){
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cable=connections.size();
        if(cable<n-1){
            return -1;
        }
        int count=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                BFS(adj,i,visited);
                count++;
            } 
        }
        return count-1;
    }
};