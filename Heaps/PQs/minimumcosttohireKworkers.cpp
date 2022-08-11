class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> v;
        int n=quality.size();
        for(int i=0;i<n;i++){
            double factor=wage[i]/(double) quality[i];
            v.push_back({factor,quality[i]});
        }
        sort(v.begin(),v.end());
        double res=DBL_MAX;
        int sum=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(pq.size()<k){
                pq.push(v[i].second);
                sum+=v[i].second;
            }
            else if(pq.size()==k){
                if(pq.top()>v[i].second){
                    sum-=pq.top();
                    pq.pop();
                    pq.push(v[i].second);
                    sum+=v[i].second;
                }
            }
            if(pq.size()==k){
                double cost=sum*v[i].first;
                res=min(res,cost);
            }
        }
        return res;
    }
};