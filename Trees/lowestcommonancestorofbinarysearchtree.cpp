#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL) return NULL;
    if(root->val==p->val || root->val==q->val) return root;
    TreeNode* lca1=lowestCommonAncestor(root->left,p,q);
    TreeNode* lca2=lowestCommonAncestor(root->right,p,q);
    if(lca1!=NULL && lca2!=NULL) return root;
    if(lca1!=NULL) return lca1;
    else return lca2;
}
void printTree(TreeNode* root) {
    queue<TreeNode*> q; 
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        cout<<curr->val<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    TreeNode* p=new TreeNode(2);
    TreeNode* q=new TreeNode(3);
    TreeNode* res=lowestCommonAncestor(root,p,q);
    cout<<res->val;;
}