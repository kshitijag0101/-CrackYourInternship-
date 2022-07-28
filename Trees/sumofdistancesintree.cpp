class Solution {
public:
    vector<int> res;
    vector<int> count;
    int size;
    void dfs(int src,int parent,vector<int> adj[]){
        for(auto& child:adj[src]){
            if(child!=parent){
                dfs(child,src,adj);
                count[src]+=count[child];
                res[src]+=res[child]+count[child];
            }
        }
    }
    void dfs2(int src,int parent,vector<int> adj[]){
        for(auto& child:adj[src]){
            if(child!=parent){
                res[child]+=(res[src]+(size-count[child])-res[child]-count[child]);
                dfs2(child,src,adj);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        size=n;
        vector<int> adj[n];
        res.resize(n,0);
        count.resize(n,1);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1,adj);
        dfs2(0,-1,adj);
        return res;
    }
};