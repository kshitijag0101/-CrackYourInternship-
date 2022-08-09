//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    struct TrieNode{
    	unordered_map<char,TrieNode*> child;
    	bool isEnd;
    	TrieNode(){
    		for (char i='a';i <='z';i++)
    			child[i]=NULL;
    		isEnd=false;
    	}
    };
    TrieNode *root=NULL;
    void insert(string s){
    	int len=s.length();
    	TrieNode *curr=root;
    	for (int i=0;i<len;i++){
    		TrieNode *nextNode=curr->child[s[i]];
    		if(nextNode==NULL){
    			nextNode=new TrieNode();
    			curr->child[s[i]]=nextNode;
    		}
    		curr=nextNode;
    		if(i==len-1)
    			curr->isEnd=true;
    	}
    }
    void add(string s[],int n){
    	root=new TrieNode();
    	for(int i=0;i<n;i++)
    		insert(s[i]);
    }
    void displayContactsUtil(TrieNode *curr,string prefix,vector<string> &res){
    	if (curr->isEnd)
    		    res.push_back(prefix);
    	for(char i='a';i<='z';i++){
    		TrieNode *nextNode=curr->child[i];
    		if(nextNode!=NULL)
    			displayContactsUtil(nextNode,prefix+(char)i,res);
    	}
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> res;
        add(contact,n);
        TrieNode* prev=root;
        string prefix="";
        int i;
        for(i=0;i<s.length();i++){
            vector<string> v;
            prefix+=(char)s[i];
    		char lastch=prefix[i];
    		TrieNode *curr=prev->child[lastch];
    		if (curr==NULL){
    			v.push_back("0");
    			res.push_back(v);
    			i++;
    			break;
    		}
    		displayContactsUtil(curr,prefix,v);
    		prev=curr;
    		res.push_back(v);
        }
        for(;i<s.length();i++){
            vector<string> v;
    	    v.push_back("0");
    	    res.push_back(v);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends