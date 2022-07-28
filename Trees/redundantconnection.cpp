#include<bits/stdc++.h>
using namespace std;
int findParent(int n,vector<int> p){
    if(n==p[n]) return n;
    return findParent(p[n],p);
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> parent(1001,0),res;
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }
    for(auto edge:edges){
        int n1=edge[0],n2=edge[1];
        int p1=findParent(n1,parent);
        int p2=findParent(n2,parent);
        if(p1==p2){
            res=edge;
        }
        parent[p1]=p2;
    }
    return res;
}
int main(){
    vector<vector<int>> edges={{1,2},{1,3},{2,3}};
    vector<int> res=findRedundantConnection(edges);
    for(int x:res){
        cout<<x<<" ";
    }
}