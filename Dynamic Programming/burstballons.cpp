class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int dp[n][n];
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;i<n,j<n;i++,j++){
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int left=0;
                    if(k>i) left=dp[i][k-1];
                    int right=0;
                    if(k<j) right=dp[k+1][j];
                    int val=nums[k];
                    if(i>0) val*=nums[i-1];
                    if(j+1<n) val*=nums[j+1];
                    int total=val+left+right;
                    maxi=max(maxi,total);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[0][n-1];
    }
};