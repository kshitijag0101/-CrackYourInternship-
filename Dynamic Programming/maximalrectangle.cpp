class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m=matrix.size(),n=matrix[0].size(),res=0;
        vector<vector<int>> dp(m,vector<int>(n+1));
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                matrix[j][i]=='1'?c++:c=0;
                dp[j][i]=c;
            }
        }
        for(int i=0;i<m;i++){
            stack<int> st;
            for(int j=0;j<=n;j++){
                while(!st.empty() && dp[i][st.top()]>=dp[i][j]){
                    int last=st.top();
                    st.pop();
                    int sc=st.empty()?-1:st.top();
                    res=max(res,(j-1-sc)*dp[i][last]);
                }
                st.push(j);
            }
        }
        return res;
    }
};