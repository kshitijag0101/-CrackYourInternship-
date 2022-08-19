//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long getcount(char keypad[4][3],int n){
	    if(n<=0) return 0;
	    if(n==1) return 10;
	    int row[]={0,0,-1,0,1};
	    int col[]={0,-1,0,1,0};
	    long long count[10][n+1];
	    for(int i=0;i<10;i++){
	        count[i][0]=0;
	        count[i][1]=1;
	    }
	    int num=0,nextnum=0;
	    for(int k=2;k<=n;k++){
	        for(int i=0;i<4;i++){
	            for(int j=0;j<3;j++){
	                if(keypad[i][j]!='*' && keypad[i][j]!='#'){
	                    num=keypad[i][j]-'0';
	                    count[num][k]=0;
	                    for(int move=0;move<5;move++){
	                        int nrow=i+row[move];
	                        int ncol=j+col[move];
	                        if(nrow>=0 && ncol>=0 && nrow<4 && ncol<3 && keypad[nrow][ncol]!='*' && keypad[nrow][ncol]!='#'){
	                            nextnum=keypad[nrow][ncol]-'0';
	                            count[num][k]+=count[nextnum][k-1];
	                        }
	                    }
	                }
	            }
	        }
	    }
	    long long totalcount=0;
	    for(int i=0;i<10;i++){
	        totalcount+=count[i][n];
	    }
	    return totalcount;
	}
	long long getCount(int N)
	{
		char keypad[4][3]={{'1','2','3'},
                           {'4','5','6'},
                           {'7','8','9'},
                           {'*','0','#'}};
        return getcount(keypad,N);
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends