#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size(),i,j,currlen=0,cost;
        vector<int> dp(n,0),res(n,0);
        dp[n-1]=0;
        res[n-1]=n-1;
        for(i=n-2;i>=0;i--){
            currlen=-1;
            dp[i]=INT_MAX;
            for(j=i;j<n;j++){
                currlen+=(nums[j]+1);
                if(currlen>k) break;
                if(j==n-1) cost=0;
                else cost=(k-currlen)*(k-currlen)+dp[j+1];
                if(cost<dp[i]){
                    dp[i]=cost;
                    res[i]=j;
                }
            }
        }
        int ans=0;
        i=0;
        while(i<n){
            int p=0;
            for(int j=i;j<res[i]+1;j++){
                p+=nums[j];
            }
            int x=res[i]-i;
            if(res[i]+1!=nums.size()){
                ans+=(k-x-p)*(k-x-p);
            }
            i=res[i]+1;
        }
        return ans;
    } 
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
} 