class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res=0;
        priority_queue<int> pq;
        int maxreach=startFuel;
        int i=0;
        while(maxreach<target){
            while(i<stations.size() && stations[i][0]<=maxreach){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            maxreach+=pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};