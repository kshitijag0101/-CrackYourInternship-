class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> costs(n,INT_MAX),temp(n,INT_MAX);
        costs[src]=0;
        temp[src]=0;
        for(int i=0;i<=k;i++){
            for(auto x:flights){
                int sr=x[0];
                int dt=x[1];
                int cost=x[2];
                if(temp[sr]!=INT_MAX){
                    costs[dt]=min(costs[dt],temp[sr]+cost);
                }
            }
            temp=costs;
        }
        if(costs[dst]==INT_MAX) return -1;
        return costs[dst];
    }
};