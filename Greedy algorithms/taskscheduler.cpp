class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        unordered_map<char,int> mp;
        int count=0;
        for(auto ch:tasks){
            mp[ch]++;
            count=max(count,mp[ch]);
        }
        int res=(count-1)*(n+1);
        for(auto x:mp){
            if(x.second==count) res++;
        }
        return max(size,res);
    }
};