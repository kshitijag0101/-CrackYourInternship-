class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int dp[n+1][n+1];
        string temp=s;
        reverse(s.begin(),s.end());
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(s[i-1]==temp[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};