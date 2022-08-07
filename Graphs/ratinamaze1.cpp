//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void getPath(vector<vector<int>> &m,int n,int row,int col,vector<string> &res,string curr){
        if(row<0 || col<0 || row>=n || col>=n || m[row][col]==0){
            return;
        }
        if(row==n-1 and col==n-1){
            res.push_back(curr);return;
        }
        m[row][col]=0;
        getPath(m,n,row-1,col,res,curr+'U');
        getPath(m,n,row+1,col,res,curr+'D');
        getPath(m,n,row,col-1,res,curr+'L');
        getPath(m,n,row,col+1,res,curr+'R');
        m[row][col]=1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        getPath(m,n,0,0,res,"");
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends