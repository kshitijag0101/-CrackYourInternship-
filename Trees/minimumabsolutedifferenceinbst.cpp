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
TreeNode* pre=NULL;
int mini=INT_MAX;
void find(TreeNode* root){
    if(root->left) find(root->left);
    if(pre) mini=min(mini,abs(root->val-pre->val));
    pre=root;
    if(root->right) find(root->right);
}
int getMinimumDifference(TreeNode* root) {
    find(root);
    return mini;
}
int main(){
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    int res=getMinimumDifference(root);
    cout<<res<<endl;
}