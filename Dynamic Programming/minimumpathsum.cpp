class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                }
                else{
                    int up=grid[i][j];
                    int left=grid[i][j];
                    if(i>0){
                        up+=dp[i-1][j];
                    }
                    else{
                        up+=1e9;
                    }
                    if(j>0){
                        left+=dp[i][j-1];
                    }
                    else{
                        left+=1e9;
                    }
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};