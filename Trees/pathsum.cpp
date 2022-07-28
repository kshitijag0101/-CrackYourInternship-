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
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            return targetSum==root->val;
        }
        if(hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum - root->val)) return true;
    }
    return false;
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    bool res=hasPathSum(root,4);
    if(res) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}