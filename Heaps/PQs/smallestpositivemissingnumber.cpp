//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++){
            while (arr[i]>=1 && arr[i]<=n && arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }
        }
        for(int i=0;i<n;i++) {
            if (arr[i]!=i+1) {
                return i+1;
            }
        }
        return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends


// Using Priority Queue Leetcode-

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=1;
        for(int j=0;j<nums.size();j++){
            if(nums[j]>0){
                if(nums[j]>i){
                    pq.push(nums[j]);
                }
                if(i==nums[j]){
                    i++;
                }
            }
        }
        while(!pq.empty()){
            if(pq.top()==i) i++;
            pq.pop();
        }
        return i;
    }
};