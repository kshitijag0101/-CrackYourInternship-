class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> mp;
        for(auto x:adjacentPairs){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        int n=adjacentPairs.size()+1;
        vector<int> res(n,-1);
        int i=0;
        for(auto x:mp){
            if(x.second.size()==1){
                res[0]=x.first;
                i++;
                break;
            }
        }
        while(i<n){
            vector<int> curr=mp[res[i-1]];
            if(curr.size()==1){
                res[i]=curr[0];
                i++;
            }
            else{
                int prev=res[i-2];
                res[i]=(curr[0]==prev)?curr[1]:curr[0];
                i++;
            }
        }
        return res;
    }
};