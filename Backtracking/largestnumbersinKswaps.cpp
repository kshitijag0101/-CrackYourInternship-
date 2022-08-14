//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void find(string str, int k, string& maxstr, int ctr){
        if(k==0) return;
        int n=str.length();
        char maxi=str[ctr];
        for (int j=ctr+1;j<n;j++) {
            if(maxi<str[j]){
                maxi=str[j];
            } 
        }
        if(maxi!=str[ctr]) k--;
        for (int j=n-1;j>=ctr;j--){
            if(str[j]==maxi) {
                swap(str[ctr], str[j]);
                if (str.compare(maxstr)>0) maxstr=str;
                find(str,k,maxstr,ctr+1);
                swap(str[ctr],str[j]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       string maxstr=str;
       find(str,k,maxstr,0);
       return maxstr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends