class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        int maxi=nums[0],mini=nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(maxi,mini);
            maxi=max(nums[i],nums[i]*maxi);
            mini=min(nums[i],nums[i]*mini);
            dp[i]=max(dp[i-1],maxi);
        }
        return dp[n-1];
    }
};