class Solution {
public:
    int DFS(int id,vector<vector<int>>& adj,vector<int>& informTime){
        if(adj[id].size()==0) return 0;
        int time=0;
        for(int i=0;i<adj[id].size();i++){
            time=max(time,DFS(adj[id][i],adj,informTime));
        }
        return time+informTime[id];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1) return 0;
        int time[n];
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return DFS(headID,adj,informTime);
    }
};