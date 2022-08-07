//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int m,int n,int N){
        if (m>=1 && m<=N && n>=1 && n<=N) return true;
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
        queue<pair<pair<int,int>,int>> q;
        q.push({{KnightPos[0],KnightPos[1]},0});
        bool visit[N+1][N+1];
        for(int i=1;i<=N;i++){
            for(int j=0;j<=N;j++){
                visit[i][j]=false;
            }
        }
        visit[KnightPos[0]][KnightPos[1]]=true;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            if(x==TargetPos[0] && y==TargetPos[1]){
                return dist;
            } 
            for(int i=0;i<8;i++){
                int m=x+dx[i];
                int n=y+dy[i];
                if(isValid(m,n,N) && !visit[m][n]){
                    visit[m][n]=true;
                    q.push({{m,n},dist+1});
                }
            }
        }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends