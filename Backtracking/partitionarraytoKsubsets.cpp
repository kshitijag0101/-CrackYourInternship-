//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossibleRec(int a[],int subsetsum[],bool visited[],int subset,int k,int n,int currind,int lastind){
        if(subsetsum[currind]==subset){
            if(currind==k-2){
                return true;
            }
            return isKPartitionPossibleRec(a,subsetsum,visited,subset,k,n,currind+1,n-1);
        }
        for(int i=lastind;i>=0;i--){
            if(visited[i]) continue;
            int temp=subsetsum[currind]+a[i];
            if(temp<=subset){
                visited[i]=true;
                subsetsum[currind]+=a[i];
                bool flag=isKPartitionPossibleRec(a,subsetsum,visited,subset,k,n,currind,i-1);
                visited[i]=false;
                subsetsum[currind]-=a[i];
                if(flag) return true;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         if(k==1) return true;
         if(n<k) return false;
         int sum=0;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         if(sum%k!=0) return false;
         int subset=sum/k;
         int subsetsum[k];
         bool visited[n];
         for(int i=0;i<k;i++){
             subsetsum[i]=0;
         }
         for(int i=0;i<n;i++){
             visited[i]=false;
         }
         subsetsum[0]=a[n-1];
         visited[n-1]=true;
         return isKPartitionPossibleRec(a,subsetsum,visited,subset,k,n,0,n-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends