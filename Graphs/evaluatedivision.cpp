class Solution {
public:
    void DFS(map<string,vector<string>>& graph,map<string,double>& mp,map<string,int>& visited,string start,string end,double& val,bool& found){
        visited[start]=1;
        if(found==true) return;
        for(auto x:graph[start]){
            if(visited[x]!=1){
                val*=mp[start+"-"+x];
                if(end==x){
                    found=true;
                    return;
                }
                 DFS(graph,mp,visited,x,end,val,found);
                if(found==true) return;
                else{
                    val/=mp[start+"-"+x];
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        map<string,double> mp;
        map<string,vector<string>> graph;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"-"+v]=values[i];
            mp[v+"-"+u]=1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(graph.find(start)==graph.end() || graph.find(end)==graph.end()){
                res.push_back(-1);
            }
            else{
                double val=1;
                map<string,int> visited;
                bool found=false;
                if(start==end){
                    found=true;
                }
                else{
                    DFS(graph,mp,visited,start,end,val,found);
                }
                if(found==true){
                    res.push_back(val);
                }
                else{
                    res.push_back(-1);
                }
            }
        }
        return res;
    }
};