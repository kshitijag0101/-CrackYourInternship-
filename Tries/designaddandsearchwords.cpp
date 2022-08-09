class WordDictionary {
public:
    struct TrieNode{
        vector<TrieNode*> child;
        bool isEnd;
        TrieNode(){
            isEnd=false;
            child.resize(26,NULL);
        }
    };
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr=root;
        for(char c:word){
            if(curr->child[c-'a']==NULL){
                curr->child[c-'a']=new TrieNode();
            }
            curr=curr->child[c-'a'];
        }
        curr->isEnd=true;
    }
    bool DFS(string& word,int i,TrieNode* curr){
        if(curr==NULL) return false;
        if(i==word.size()) return curr->isEnd;
        for(;i<word.size();i++){
            char c=word[i];
            if(c=='.'){
                for(auto x: curr->child){
                    if(DFS(word,i+1,x)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(curr->child[c-'a']==NULL) return false;
                curr=curr->child[c-'a'];
            }
        }
        return curr->isEnd;
    }
    bool search(string word) {
        return DFS(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */