class Solution {
public:
    int solveSubProblem(int left,int right,int sameBoxes,vector<int>& boxes,int dp[100][100][100]){
        if(left>right) return 0;
        if(dp[left][right][sameBoxes]>0){
            return dp[left][right][sameBoxes];
        }
        int points=(sameBoxes+1)*(sameBoxes+1) + solveSubProblem(left+1,right,0,boxes,dp);
        for(int mid=left+1;mid<=right;mid++){
            if(boxes[left]==boxes[mid]){
                points=max(points,solveSubProblem(left+1,mid-1,0,boxes,dp) + solveSubProblem(mid,right,sameBoxes+1,boxes,dp));
            }
        }
        dp[left][right][sameBoxes]=points;
        return points;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        int dp[100][100][100]={0};
        return solveSubProblem(0,n-1,0,boxes,dp);
    }
};