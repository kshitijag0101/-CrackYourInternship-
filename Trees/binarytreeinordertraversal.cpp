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
vector<int> res;
void inorder(TreeNode* root){
    if(root!=NULL){
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    inorder(root);
    return res;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    vector<int> ans=inorderTraversal(root);
    for(int x:ans) cout<<x<<" ";
}