class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        if(k>n/2){
            int res=0;
            for(int i=1;i<n;i++){
                res+=max(prices[i]-prices[i-1],0);
            }
            return res;
        }
        int hold[k+1];
        int dp[k+1];
        for(int i=0;i<=k;i++){
            hold[i]=INT_MIN;
            dp[i]=0;
        }
        int curr;
        for(int i=0;i<n;i++){
            curr=prices[i];
            for(int j=k;j>0;j--){
                dp[j]=max(dp[j],hold[j]+curr);
                hold[j]=max(hold[j],dp[j-1]-curr);
            }
        }
        return dp[k];
    }
};