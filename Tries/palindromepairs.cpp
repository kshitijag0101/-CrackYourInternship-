class TrieNode{
    public:
        vector<TrieNode*> child;
        int index;
        vector<int> list;
        TrieNode(){
            child=vector<TrieNode*>(26);
            index=-1;
        }
};
class Trie{
private:
    TrieNode* root;
    bool isPalindrome(string& s,int l,int r){
        for(;l<r;l++,r--){
            if(s[l]!=s[r]) return false;
        }
        return true;
    }
public:
    Trie(){
        root=new TrieNode();
    }
    void add(string& word,int index){
        TrieNode* curr=root;
        for(int i=word.size()-1;i>=0;i--){
            if(isPalindrome(word,0,i)){
                curr->list.push_back(index);
            }
            char c=word[i];
            if(curr->child[c-'a']==NULL){
                curr->child[c-'a']=new TrieNode;
            }
            curr=curr->child[c-'a'];
        }
        curr->index=index;
        curr->list.push_back(index);
    }
    void find(string& word,int index,vector<vector<int>>& res){
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->index!=-1 && curr->index!=index && isPalindrome(word,i,word.size()-1)){
                res.push_back({index,curr->index});
            }
            char c=word[i];
            if(curr->child[c-'a']==NULL) return;
            curr=curr->child[c-'a'];
        }
        for(int ind:curr->list){
            if(ind==index) continue;
            res.push_back({index,ind});
        }
    }
};
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        Trie* trie=new Trie;
        int n=words.size();
        for(int i=0;i<n;i++){
            trie->add(words[i],i);
        }
        for(int i=0;i<n;i++){
            trie->find(words[i],i,res);
        }
        return res;
    }
};