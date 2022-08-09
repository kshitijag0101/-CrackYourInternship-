//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++){
                child[i]=NULL;
            }
            isEnd=false;
        }
    };
    TrieNode* root=new TrieNode;
    void insert(TrieNode* root,string key){
        TrieNode* curr=root;
        for (int i=0;i<key.length();i++){
            int index=key[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index]=new TrieNode;
            curr=curr->child[index];
        }
        curr->isEnd=true;
    }
    bool search(TrieNode* root,string key){
        TrieNode* curr=root;
        for (int i=0;i<key.length();i++){
            int index=key[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr=curr->child[index];
        }
        return(curr!=NULL && curr->isEnd);
    }
    bool wordBreak2(string str,TrieNode* root){
        int size=str.size();
        if (size==0) return true;
        for (int i=1;i<=size;i++) {
            if (search(root,str.substr(0,i)) && wordBreak2(str.substr(i,size-i),root))
                return true;
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        for(int i=0;i<B.size();i++){
            insert(root,B[i]);
        }
        if(wordBreak2(A,root)) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends