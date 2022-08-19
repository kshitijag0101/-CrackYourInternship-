class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n=stones.size();
        vector<int> prefix(n,0);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stones[i];
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(K+1,INT_MAX)));
        for(int i=0;i<n;i++){
            dp[i][i][1]=0;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                for(int k=2;k<=K;k++){
                    if(k>len) continue;
                    for(int m=i;m<j;m++){
                        if(dp[i][m][1]==INT_MAX || dp[m+1][j][k-1]==INT_MAX) continue;
                        dp[i][j][k]=min(dp[i][j][k],dp[i][m][1]+dp[m+1][j][k-1]);
                    }
                }
                if(dp[i][j][K]!=INT_MAX){
                    dp[i][j][1]=dp[i][j][K]+prefix[j]-((i-1>=0)?prefix[i-1]:0);
                }
            }
        }
        return ((dp[0][n-1][1]==INT_MAX)?-1:dp[0][n-1][1]);
    }
};