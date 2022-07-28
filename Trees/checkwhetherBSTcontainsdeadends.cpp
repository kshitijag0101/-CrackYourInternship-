#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int x){
        data = x;
        left = NULL;
        right = NULL;
	}
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree)){
        temp = new Node(val);
        *tree = temp;
        return;
    }
    if(val < (*tree)->data){
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data){
        insert(&(*tree)->right, val);
    }
}
void fill(Node* root,unordered_set<int>& nodes,unordered_set<int>& lnodes){
    if(root==NULL) return;
    nodes.insert(root->data);
    if(root->left==NULL && root->right==NULL){
        lnodes.insert(root->data);
    }
    fill(root->left,nodes,lnodes);
    fill(root->right,nodes,lnodes);
}
bool isDeadEnd(Node *root){
    if(root==NULL) return false;
    unordered_set<int> nodes,lnodes;
    nodes.insert(0);
    fill(root,nodes,lnodes);
    for(auto x:lnodes){
        if(nodes.find(x-1)!=nodes.end() && nodes.find(x+1)!=nodes.end()){
            return true;
        }
    }
    return false;
}
bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

