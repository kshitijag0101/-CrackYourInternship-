//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int src, vector<int>adj[],int visited[]){
        queue<int> q;
        q.push(src);
	    while(!q.empty()){
	        int u=q.front();
	        q.pop();
	        for(auto v:adj[u]){
	            if(visited[v]==-1){
	                visited[v]=1-visited[u];
	                q.push(v);
	            }
	            else if(visited[v]==visited[u]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    int visited[V];
	    memset(visited,-1,sizeof(visited));
	    for(int i=0;i<V;i++){
	        if(visited[i]==-1){
	            if(!check(i,adj,visited)){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends