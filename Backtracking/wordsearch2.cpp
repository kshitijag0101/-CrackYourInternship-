class Solution {
public:
    vector<string> res;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    class Trie{
        public:
            Trie* child[26];
            bool isEnd=false;
    };
    void insert(Trie* root,string& word){
        Trie* curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]=new Trie();
            }
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    bool issafe(vector<vector<char>>& board,int x,int y){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='*') return false;
        return true;
    }
    void search(vector<vector<char>>& board,int x,int y,Trie* root,string& str){
        if(board[x][y]=='*') return;
        int index=board[x][y]-'a';
        if(root->child[index]==NULL) return;
        str.push_back(board[x][y]);
        char ch=board[x][y];
        board[x][y]='*';
        if(root->child[index]->isEnd){
            res.push_back(str);
            root->child[index]->isEnd=false;
        }
        for(int i=0;i<4;i++){
            int newx=x+dx[i],newy=y+dy[i];
            if(issafe(board,newx,newy)){
                search(board,newx,newy,root->child[index],str);
            }
        }
        board[x][y]=ch;
        str.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *root=new Trie();
        for(auto& word:words){
            insert(root,word);
        } 
        int row=board.size(),col=board[0].size();
        string str="";
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                search(board,i,j,root,str);
            }
        }
        return res;
    }
};