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
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1==NULL && root2==NULL) return NULL;
    int val1=(root1!=NULL)?root1->val:0;
    int val2=(root2!=NULL)?root2->val:0;
    TreeNode* root=new TreeNode(val1+val2);
    if(root1==NULL){
        root->left=mergeTrees(root1,root2->left);
        root->right=mergeTrees(root1,root2->right);
    }
    else if(root2==NULL){
        root->left=mergeTrees(root1->left,root2);
        root->right=mergeTrees(root1->right,root2);
    }
    else{
        root->left=mergeTrees(root1->left,root2->left);
        root->right=mergeTrees(root1->right,root2->right);
    }
    return root;
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
    TreeNode* root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root1->left->left=new TreeNode(4);
    root1->left->right=new TreeNode(5);
    TreeNode* root2=new TreeNode(1);
    root2->left=new TreeNode(2);
    root2->right=new TreeNode(3);
    root2->left->left=new TreeNode(4);
    root2->left->right=new TreeNode(5);
    TreeNode* root=mergeTrees(root1,root2);
    printTree(root);
}