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
int res=0;
int height(TreeNode* root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    res=max(res,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    int h=height(root);
    return res;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    int res=diameterOfBinaryTree(root);
    cout<<res<<endl;
}