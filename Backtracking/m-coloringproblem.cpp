//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool issafe(bool graph[101][101],vector<int>&color,int i,int j,int n){
        for(int k=0;k<n;k++){
            if(graph[i][k]==1 && color[k]==j) return false;
        }
        return true;
    }
    bool solve(bool graph[101][101], int m, int n,vector<int>&color,int i){
        if(i==n) return true;
        for(int j=0;j<m;j++){
            if(issafe(graph,color,i,j,n)){
                color[i]=j;
                if(solve(graph,m,n,color,i+1)) return true;
                color[i]=-1;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,-1);
        return solve(graph,m,n,color,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends