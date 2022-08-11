class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};