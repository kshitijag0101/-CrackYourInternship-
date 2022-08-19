class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int mx= INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            mp[nums[i]]++;
        }
        vector<int> dp(mx+1,0);
        for(int i=1;i<=mx;i++){
            if(mp[i]>0){
                if(i==1){
                    dp[i]=mp[i];
                }
                else{
                    dp[i]=max(dp[i-1],(i*mp[i])+dp[i-2]);
                }
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[mx];
    }
};