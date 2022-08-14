class Solution {
public:
    void subset(vector<int>& nums,vector<vector<int>>& res,vector<int> temp,int ind){
        if(ind>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        subset(nums,res,temp,ind+1);
        temp.pop_back();
        subset(nums,res,temp,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        subset(nums,res,temp,0);
        return res;
    }
};