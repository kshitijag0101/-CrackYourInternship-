//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        long long int num1=0,num2=0;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        while(!pq.empty()){
            num1=num1*10+pq.top();
            pq.pop();
            if(!pq.empty()){
                num2=num2*10+pq.top();
                pq.pop();
            }
        }
        return num1+num2;
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends