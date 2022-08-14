class Solution {
public:
    void backtrack(int m,int& n,int& k,vector<int>& temp,vector<vector<int>>& res){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=m;i<n;i++){
            temp.push_back(i+1);
            backtrack(i+1,n,k,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(0,n,k,temp,res);
        return res;
    }
};