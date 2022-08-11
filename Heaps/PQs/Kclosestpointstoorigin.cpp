class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> pq;
        for(auto point:points){
            double dist=sqrt(point[0]*point[0] + point[1]*point[1]);
            pq.push({dist,point});
        }
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};