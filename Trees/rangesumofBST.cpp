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
int sum=0;
int inorder(TreeNode* root, int low, int high){
    if(root!=NULL){
        inorder(root->left,low,high);
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        inorder(root->right,low,high);
    }
    return sum;
}
int rangeSumBST(TreeNode* root, int low, int high) {
    if(root==NULL) return 0;
    return inorder(root,low,high);
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    int res=rangeSumBST(root,2,4);
    cout<<res<<endl;
}