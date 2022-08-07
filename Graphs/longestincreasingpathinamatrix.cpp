class Solution {
public:
    int lip(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
            return 0;
        if(dp[i][j]>0)
            return dp[i][j];
        int currmax=1;
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            currmax=max(currmax,1+lip(matrix,i+1,j,dp));
        }
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            currmax=max(currmax,1+lip(matrix,i,j+1,dp));
        }
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            currmax=max(currmax,1+lip(matrix,i-1,j,dp));
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            currmax=max(currmax,1+lip(matrix,i,j-1,dp));
        }
        dp[i][j]=currmax;
        return currmax;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxi=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxi=max(maxi,lip(matrix,i,j,dp));
            }
        }
        return maxi;
    }
};