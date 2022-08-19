class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        int prev[n],next[n],dp[n][n];
        int mod=1e9+7;
        map<char,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                prev[i]=mp[s[i]];
            }
            else{
                prev[i]=-1;
            }
            mp[s[i]]=i;
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            if(mp.find(s[i])!=mp.end()){
                next[i]=mp[s[i]];
            }
            else{
                next[i]=-1;
            }
            mp[s[i]]=i;
        }
        for(int i=1;i<=n;i++){
            for(int right=i-1;right<n;right++){
                int left=right-i+1;
                if(i==1){
                    dp[left][right]=1;
                }
                else if(i==2){
                    dp[left][right]=2;
                }
                else{
                    if(s[left]!=s[right]){
                        dp[left][right]=((dp[left][right-1]+dp[left+1][right])%mod-dp[left+1][right-1]+mod)%mod;
                    }
                    else{
                        if(next[left]>prev[right]){
                            dp[left][right]=(2*dp[left+1][right-1]+2)%mod;
                        }
                        else if(next[left]==prev[right]){
                            dp[left][right]=(2*dp[left+1][right-1]+1)%mod;
                        }
                        else{
                            dp[left][right]=((2*dp[left+1][right-1])%mod-(prev[right]-next[left]>1 ? dp[next[left]+1][prev[right]-1] : 0)+mod)%mod;
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};