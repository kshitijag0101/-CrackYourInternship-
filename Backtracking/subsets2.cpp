class Solution {
public:
    void backtrack(vector<int>& nums,vector<int>& temp,vector<vector<int>>& res,int loc){
        res.push_back(temp);
        for(int i=loc ;i<nums.size();i++){
            if(i>loc && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            backtrack(nums,temp,res,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums,temp,res,0);
        return res;
    }
};