// A C++ program to implement greedy algorithm for graph coloring
#include <bits/stdc++.h>
using namespace std;
void addEdge(int v, int w,vector<vector<int>>& adj){
	adj[v].push_back(w);
	adj[w].push_back(v); 
}
void greedyColoring(int V,vector<vector<int>>& adj){
	int result[V];
	result[0] = 0;
	for (int u = 1; u < V; u++)
		result[u] = -1;
	bool available[V];
	for (int i=0;i<V;i++)
		available[i] = false;
	for (int u = 1; u < V; u++){
		for (auto i = adj[u].begin(); i != adj[u].end(); i++)
			if (result[*i] != -1)
				available[result[*i]] = true;
		int cr;
		for (cr = 0; cr < V; cr++)
			if (available[cr] == false)
				break;
		result[u] = cr;
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = false;
	}
	for (int u = 0; u < V; u++)
		cout << "Vertex " << u << " ---> Color "<< result[u] << endl;
}

// Driver program to test above function
int main(){
    int V=5;
	vector<vector<int>> adj(V,vector<int>());
	addEdge(0, 1,adj);
	addEdge(0, 2,adj);
	addEdge(1, 2,adj);
	addEdge(1, 3,adj);
	addEdge(2, 3,adj);
	addEdge(3, 4,adj);
	cout << "Coloring of graph  \n";
	greedyColoring(V,adj);
	return 0;
}
