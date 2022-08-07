class Solution {
public:
    bool DFS(vector<vector<int>>&graph,int s,vector<bool>& visited,vector<bool>& recvisited,vector<bool>& cycle) {
        visited[s]=true;
        recvisited[s]=true;
        for(auto x:graph[s]) {
            if(visited[x]==false) {
                if(DFS(graph,x,visited,recvisited,cycle)) {
                    cycle[s] = true;
                    return true;
                }
            }
            else if(visited[x]==true && recvisited[x]==true) {
                cycle[s] = true;
                return true;
            }
        }
        recvisited[s]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n,false),recvisited(n,false),cycle(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                DFS(graph,i,visited,recvisited,cycle);
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(cycle[i]==false){
                res.push_back(i);
            }
        }
        return res;
    }
};