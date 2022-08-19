class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> v={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        long long dp[n+1][10];
        int mod=pow(10,9)+7;
        for(int i=0;i<10;i++){
            dp[0][i]=0;
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<10;j++){
                long long sum=0;
                for(int num:v[j]){
                    sum=(sum+dp[i-1][num]%mod)%mod;
                }
                dp[i][j]=sum;
            }
        }
        int res=0;
        for(int i=0;i<10;i++){
            res=(res+dp[n][i]%mod)%mod;
        }
        return res;
    }
};