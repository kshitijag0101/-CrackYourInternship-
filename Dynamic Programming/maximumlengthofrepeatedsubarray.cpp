class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
            }
        }
        int res=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};