#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& board,vector<vector<int>> res,int row,int col){
    int count1=0;
    int index[8][2]={{0,-1},{0,1},{1,-1},{1,1},{-1,-1},{1,0},{-1,0},{-1,1}};
    for(int i=0;i<8;i++){
        int x=row+index[i][0];
        int y=col+index[i][1];
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size()){
            continue;
        }
        if(res[x][y]==1){
            count1++;
        }
        x=row;
        y=col;
    }
    if(res[row][col]==0 && count1==3){
        board[row][col]=1;
    }
    else if(res[row][col]==1 && count1==1 || count1==0){
        board[row][col]=0;
    }
    else if(res[row][col]==1 && count1>3){
        board[row][col]=0;
    }
    else if(res[row][col]==1 && count1==2 || count1==3){
        board[row][col]=1;
    }
}
void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> res=board;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            solve(board,res,i,j);
        }
    }
}
int main(){
    int r,c,x;
    cin>>r>>c;
    vector<vector<int>> board;
    for(int i=0;i<r;i++){
        vector<int> mat;
        for(int j=0;j<c;j++){
            cin>>x;
            mat.push_back(x);
        }
        board.push_back(mat);
    }
    gameOfLife(board);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}