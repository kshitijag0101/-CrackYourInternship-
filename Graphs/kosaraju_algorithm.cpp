//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void DFSuntil(int s,vector<int> adj[],bool visited[]){
	    visited[s]=true;
	    for(auto x:adj[s]){
	        if(visited[x]==false){
	            DFSuntil(x,adj,visited);
	        }
	    }
	}
	void fillorder(int source,vector<int> adj[],bool visited[],stack<int> &s){
	    visited[source]=true;
	    for(auto x:adj[source]){
	        if(visited[x]==false){
	            fillorder(x,adj,visited,s);
	        }
	    }
	    s.push(source);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        bool visited[V]={false};
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                fillorder(i,adj,visited,s);
            }
        }
        vector<int> graph[V];
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            graph[x].push_back(i);
	        }
	    }
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        int count=0;
        while(s.empty()==false){
            int temp=s.top();
            s.pop();
            if(visited[temp]==false){
                DFSuntil(temp,graph,visited);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends