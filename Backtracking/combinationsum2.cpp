class Solution {
public:
    void backtrack(vector<int>& candidates,int target,vector<vector<int>>& res,vector<int> temp,int index){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],res,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,res,temp,0);
        return res;
    }
};