class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char ch){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
            if(board[row][i]==ch) return false;
        }
        int boxrow=row-row%3;
        int boxcol=col-col%3;
        for(int r=boxrow;r<boxrow+3;r++){
            for(int c=boxcol;c<boxcol+3;c++){
                if(board[r][c]==ch) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(board,i,j,ch)){
                            board[i][j]=ch;
                            if(solve(board)==true) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};