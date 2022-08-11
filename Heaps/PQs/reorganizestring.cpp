class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        string res="";
        unordered_map<char,int> mp;
        for(char x:s){
            mp[x]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            res+=top1.second;
            res+=top2.second;
            if(--top1.first>0) pq.push(top1);
            if(--top2.first>0) pq.push(top2);
        }
        if(pq.size()){
            if(pq.top().first==1){
                res+=pq.top().second;
            }
            else{
                return "";
            }
        }
        return res;
    }
};